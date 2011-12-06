#coding: utf-8
__author__ = 'tural'

#на самом деле почти все проверяется правилами синтаксиса, так что нефиг придумывать

types = ['integer', 'real', 'string', 'boolean']


class Any(object):
    def __eq__(self, other):
        return True
    def __ne__(self, other):
        return False


class Context(object):
    def __init__(self, name = None):
        self.variables = {}
        self.var_count = {}
        self.name = name

    def has_var(self, name):
        return name in self.variables

    def get_var(self, name):
        return self.variables[name]

    def set_var(self, name, typ):
        self.variables[name] = typ
        self.var_count[name] = 0


contexts = list()

functions = {
    'write':('integer', [Any()], [], []),
    'writeln':('integer', [Any()], [], []),
}

def pop():
    if len(contexts) > 0:
        count = contexts[-1].var_count
        for v in count:
            if count[v] == 0:
                print "Warning: variable %s was declared. but not used." % v
        contexts.pop()

def check_if_function(var):
    if var.lower() in functions and not is_function_name(var.lower()):
        raise Exception, "A function called %s already exists" % var

def is_function_name(var):
    for i in contexts[::-1]:
        if i.name == var:
            return True
    return False

def has_var(var_name):
    var = var_name.lower()
    check_if_function(var)
    for c in contexts[::-1]:
        if c.has_var(var):
            return True
    return False

def get_var(var_name):
    var = var_name.lower()
    for c in contexts[::-1]:
        if c.has_var(var):
            c.var_count[var] += 1
            return c.get_var(var)
    raise Exception, "Variable %s is referenced before assignment" % var

def set_var(var_name, var_type):
    var = var_name.lower()
    check_if_function(var)
    now = contexts[-1]
    if now.has_var(var):
        raise Exception, "Variable %s already defined" % var
    else:
        now.set_var(var, var_type.lower())

def get_params(node):
    if node.type == "formal_parameter":
        return [check(node.args[0])]
    else:
        ls = list()
        for i in node.args:
            ls.extend(get_params(i))
        return ls

def flatten(n):
    if not is_node(n):
        return [n]
    if not n.type.endswith("_list"):
        return list(n.args)
    else:
        ls = list()
        for i in n.args:
            ls.extend(flatten(i))
        return ls

def is_node(node):
    return hasattr(node, "type")

def get_type(node):
    if node.type == "left_part_list":
        left_parts = flatten(node)
        first_var_type = None
        for part in left_parts:
            if is_function_name(part.args[0]):
                var_type = functions[varn][0]
            else:
                if not has_var(part.args[0]):
                    raise Exception, "Variable %s not declared" % part.args[0]
                var_type = get_var(part.args[0])

            if not first_var_type:
                first_var_type = var_type
            elif var_type != first_var_type:
                raise Exception, "Variable %s type is not %s" % (part.args[0], first_var_type)
        return first_var_type
    # грязный хак
    elif node.type == "arithmetic_expression":
        return ["integer", "real"]
    elif node.type == "boolean_expression":
        return ["boolean"]


def check(node):
    if not is_node(node):
        if hasattr( node, "__iter__" ) and not isinstance(node, str):
            for i in node:
                check(i)
        else:
            return  node
    else:
        #обработка идентификатора
        if node.type in ["identifier"]:
            return node.args[0]

        #работа со списками
        elif node.type in ["identifier_list", "array_list", "bound_pair_list", "switch_list", "formal_parameter_list",
                           "left_part_list", "actual_parameter_list", "for_list", "for_list_element", "subscript_list",
                           "type_list","unlabeled_block","block_head", "compound_statement", "compound_tail",
                           "declaration", "formal_parameter_part", "unconditional_statement", "basic_statement",
                           "label", "unlabelled_basic_statement", "designational_expression", "simple_designational_expression",
                           "conditional_statement","actual_parameter_part", "arithmetic_expression", "boolean_expression"]:
            return check(node.args)

        #создание контектсов. На мой взгляд programm - лишний
        elif node.type in ["program", "block", "statement"]:
            contexts.append(Context())
            check(node.args)
            pop()

        #добавляем название переменных и их типы из type_declaration
        elif node.type == "type_declaration":
            local_or_own_type = node.args[0]
            if len(local_or_own_type.args) == 1:
                var_type = local_or_own_type.args[0].args[0]
            else:
                var_type = local_or_own_type.args[0].args[0] + local_or_own_type.args[0].args[1]

            type_list = flatten(node.args[1])
            for var_name in type_list:
                set_var(var_name.args[0], var_type)

        #объявление процедур. Храним название процедур(перегрузку запрещаем)
        elif node.type in ["procedure_declaration"]:
            type = None
            if len(node.args) > 2:
                type = node.args[0].args[0]
                heading = node.args[1]
                body = node.args[2]
            else:
                heading = node.args[0]
                body = node.args[1]

            proc_name = heading.args[0].args[0].lower()
            check_if_function(proc_name)

            args = list()
            value_part = list()
            specifiers = list()
            if len(heading.args) > 1:
                i = 1
                while i < len(heading.args):
                    if heading.args[i] is not None:
                        if heading.args[i].type == "formal_parameter_part":
                            if len(heading.args[i].args) > 0:
                                formal_parameter = heading.args[i].args[0]
                                if len(formal_parameter.args) > 0:
                                    args = flatten(formal_parameter.args[0])
                        elif heading.args[i].type == "value_part":
                            value_part = heading.args[i]
                            if len(value_part.args) > 0:
                                value_part = flatten(value_part.args[0])
                        elif heading.args[i].type == "specification_part":
                            specification_part = heading.args[i]
                            if len(specification_part.args) > 0:
                                specifiers = flatten(specification_part)
                    i += 1

            functions[proc_name] = (type, args, value_part, specifiers)
            check(body)
            pop()


        #вызов функции
        #TODO работает на честном слове(т.е не работает)
        elif node.type in ["procedure_statement", "function_designator"]:
            fname = node.args[0].args[0].lower()
            if fname not in functions:
                raise Exception, "Function %s is not defined" % fname
            if len(node.args) > 1:
                args = flatten(node.args[1].args[0])[0].args
            else:
                args = list()
            type, vargs, value_part, specifiers = functions[fname]

            if len(args) != len(vargs):
                raise  Exception, "Function %s is expecting %d parameters and got %d" % (fname, len(vargs), len(args))
            return type

        #присваивание
        elif node.type == "assignment_statement":
            left_part = get_type(node.args[0])
            right_part = get_type(node.args[1])

            if left_part not in right_part:
                raise Exception, "Variable(s) in left part is of type %s and does not support %s" % (left_part, right_part)

            elif node.type == "if_clause" and get_type(node.args[0]) != "boolean":
                raise Exception, "If requires an boolean expression"

            elif node.type == "for_clause":
                contexts.append(Context())
                variable = node.args[0].lower()
                set_var(variable, 'INTEGER')

                for_list = node.args[1]
                elements = flatten(for_list)
                for el in elements:
                    #arithmetic_expression
                    if get_type(el.args[0]) != "INTEGER":
                        raise Exception, "For requires an integer as a starting value"
                    #arithmetic_expression + WHILE
                    if len(el.args) == 2 and get_type(el.args[1]) != "boolean":
                        raise Exception, "For requires an boolean expression if you use WHILE"
                    #arithmetic_expression + STEP
                    elif len(el.args) == 3 and (get_type(el.args[1]) != "integer" or get_type(el.args[2]) != "integer"):
                        raise Exception, "For requires arithmetic expressions if you use STEP..UNTIL construction"
                pop()


            else:
                print "semantic missing:", node.type