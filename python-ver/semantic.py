#coding: utf-8
__author__ = 'tural'

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
    'write':('integer', [("a", Any())]),
    'writeln':('integer', [("a", Any())]),
}

def pop():
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
        return [n]
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
            if is_function_name(part.args[0].args[0]):
                var_type = functions[varn][0]
            else:
                if not has_var(part.args[0].args[0]):
                    raise Exception, "Variable %s not declared" % part.args[0].args[0]
                var_type = get_var(varn)

            if not first_var_type:
                first_var_type = var_type
            elif var_type != first_var_type:
                raise Exception, "Variable %s type is not %s" % (part.args[0].args[0], first_var_type)
        return first_var_type
    # грязный хак
    elif node.type == "arithmetic_expression":
        return ["INTEGER", "REAL"]
    elif node.type == "boolean_expression":
        return ["BOOLEAN"]


def check(node):
    if not is_node(node):
        if hasattr( node, "__iter__" ) and not isinstance(node, str):
            for i in node:
                check(i)
        else:
            return  node
    else:
        if node.type in ["identifier"]:
            return node.args[0]
        elif node.type in ["identifier_list", "array_list", "bound_pair_list", "switch_list", "formal_parameter_list",
                           "left_part_list", "actual_parameter_list", "for_list", "for_list_element", "subscript_list",
                           "type_list",]:
            return check(node.args)
        elif node.type in ["program", "block", "statement"]:
            #только ли тут?
            contexts.append(Context())
            check(node.args)
            pop()
        elif node.type in "type_declaration":
            var_type = node.args[0].args[0]
            i = 1
            while i < len(node.args):
                var_name = node.args[i].args[0]
                set_var(var_name, var_type)
                i += 1
        elif node.type in ["procedure_declaration"]:
            type = None
            if len(node.args) > 2:
                type = node.args[0].args[0]
                heading = node.args[1]
            else:
                heading = node.args[0]

            name = heading.args[0].args[0].lower()
            check_if_function(name)

            args = list()
            value_part = list()
            specifiers = list()
            if len(heading.args) > 1:
                i = 1
                while i < len(heading.args):
                    if heading.args[i].type == "formal_parameter_type":
                        formal_parameter = heading.args[i]
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

            functions[name] = (type, args, value_part, specifiers)
            check(body)
            pop()
        elif node.type in ["procedure_statement", "function_designator"]:
            fname = node.args[0].args[0].lower()
            if fname not in functions:
                raise Exception, "Function %s is not defined" % fname
            if len(node.args) > 1:
                args = get_params(node.args[1])
            else:
                args = list()
            type, vargs, value_part, specifiers = functions[fname]

            if len(args) != len(vargs):
                raise  Exception, "Function %s is expecting %d parameters and got %d" % (fname, len(vargs), len(args))
            return type

        elif node.type == "assignment_statement":
            left_part = get_type(node.args[0])
            right_part = get_type(node.args[1])

            if left_part not in right_part:
                raise Exception, "Variable(s) in left part is of type %s and does not support %s" % (left_part, right_part)
            elif node.type == "and_or":
                op = node.args[0].args[0]
                for i in range(1,2):
                    a = check(node.args[i])
                    if a != "boolean":
                        raise Exception, "%s requires a boolean. Got %s instead." % (op, a)

            elif node.type == "op":
                op = node.args[0].args[0]
                vt1 = check(node.args[1])
                vt2 = check(node.args[2])

                if vt1 != vt2:
                    raise Exception, "Arguments of operation '%s' must be of the same type. Got %s and %s" % (op, vt1, vt2)

                if op in ['mod', 'div'] and vt1 != "integer":
                    raise Exception, "Operation %s requires integers" % op

                if op == "/" and vt1 != "real":
                    raise Exception, "Operation %s requires real" % op

                if op in ['=', '<=', '>=', '<', '>', '<>']:
                    return 'boolean'
                else:
                    return vt1

            elif node.type in ['if', 'while', 'repeat']:
                if node.type == 'repeat':
                    c = 1
                else:
                    c = 0
                t = check(node.args[c])
                if t != 'boolean':
                    raise Exception, "%s condition requires a boolean. Got %s instead." % (node.type, t)

                #body
                check(node.args[1-c])

                #else
                if len(node.args) > 2:
                    check(node.args[2])

            elif node.type == "for":
                contexts.append(Context())
                v = node.args[0].args[0].args[0].lower()
                set_var(v, 'INTEGER')

                st = node.args[0].args[1].args[0].type.lower()
                if st != 'integer':
                    raise Exception, "For requires an integer as a starting value"

                fv = node.args[2].args[0].type.lower()
                if fv != 'integer':
                    raise Exception, "For requires an integer as a final value"

                check(node.args[3])
                pop()


            elif node.type == 'not':
                return check(node.args[0])

            elif node.type == "element":
                if node.args[0].type == 'identifier':
                    return get_var(node.args[0].args[0])
                elif node.args[0].type == "function_call_inline":
                    return check(node.args[0])
                else:
                    if node.args[0].type in types:
                        return node.args[0].type
                    else:
                        return check(node.args[0])

            else:
                print "semantic missing:", node.type