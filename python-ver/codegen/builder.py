#coding: utf-8
import sys

from llvm import *
from llvm.core import *

import ptypes as types
from helpers import *
from ast import Node
from context import Context



class Writer(object):
    def __init__(self):
        self.functions={}
        self.contexts = []
        self.counter = 0

    def flatten(self, n):
        if not n.__class__ == Node:
            return [n]
        if not n.type.endswith("_list"):
            return list(n.args)
        else:
            ls = list()
            for i in n.args:
                ls.extend(self.flatten(i))
            return ls

    def get_var(self,name):
        for c in self.contexts[::-1]:
            if c.has_variable(name):
                return c.get_variable(name)
        raise Exception, "Variable %s doesn't exist" % name

    def set_var(self,name,value):
        self.contexts[-1].set_variable(name,value)

    def set_param(self,name,value):
        self.contexts[-1].set_param(name,value)

    def get_builder(self):
        return self.contexts[-1].get_builder()

    def get_current(self):
        return self.contexts[-1].current

    def get_function(self):
        for c in self.contexts[::-1]:
            if c.current.__class__ == Function:
                return c.current

    def descend(self,node):
        return self(node)

    def term(self, node):
        if len(node.args) == 1:
            return self.factor(node.args[0])
        else:
            builder = self.get_builder()
            if node.args[1].args[0] == '*':
                return builder.mul(self.descend(node.args[0]), self.factor(node.args[0]))
            elif node.args[1].args[0] == '/':
                return builder.fdiv(self.descend(node.args[0]), self.factor(node.args[0]))
            elif node.args[1].args[0] == '%':
                return builder.urem(self.descend(node.args[0]), self.factor(node.args[0]))

    def factor(self, node):
        if len(node.args) == 1:
            if node.type == 'primary':
                return self.descend(node.args[0])
            else:
                return self.factor(node.args[0])
        else:
            raise Exception("Power operation not realized")

    def __call__(self,ast):
        if ast.__class__ != Node:
            return ast

        if ast.type == "program":
            mod_name = "algol_program"
            self.module = Module.new(mod_name)
            stdio = add_stdio(self.module)
            for f in stdio:
                self.functions[f] = stdio[f]

            main = create_main(self.module)

            block = Builder.new(main.append_basic_block("entry"))

            self.contexts.append(Context(main,block))
            self.descend(ast.args[0])

            self.get_builder().ret(c_int(0))

            return self.module

        elif ast.type in ["block", "statement", "array_list", "bound_pair_list", "switch_list", "formal_parameter_list",
                           "for_list", "for_list_element", "subscript_list",
                           "type_list","unlabeled_block","block_head", "compound_statement", "compound_tail",
                           "declaration", "formal_parameter_part", "unconditional_statement", "basic_statement",
                           "unlabelled_basic_statement", "boolean_expression"]:
            for son in ast.args:
                self.descend(son)

        elif ast.type in ["expression", "label"]:
            return self.descend( ast.args[0])

        elif ast.type == "designational_expression":
            if len(ast.args) == 1:
                return self.descend( ast.args[0])

        elif ast.type == "simple_designational_expression":
            return self.descend( ast.args[0])

        elif ast.type == "actual_parameter_part":
            return self.descend(ast.args[0])

        elif ast.type == "actual_parameter_list":
            builder = self.get_builder()
            if len(ast.args) == 1:
                var = self.descend(ast.args[0])
                if isinstance(var, str):
                    return [builder.load(self.get_var(var))]
                return [var]
            else:
                ls = list()
                ls.extend(self.descend(ast.args[0]))
                var = self.get_var( self.descend(ast.args[2]) )
                ls.append(var)
                return ls

        elif ast.type == "actual_parameter":
            return self.descend(ast.args[0])

        elif ast.type in ["function_designator", "procedure_statement"]:
            builder = self.get_builder()
            function_name = self.descend(ast.args[0])

            arguments = list()
            if ast.args[1]:
                arguments = self.descend(ast.args[1])

            function = self.module.get_function_named(function_name)
            return builder.call(function, arguments)

        elif ast.type == "boolean_expression":
            pass

        elif ast.type == "if_statement":
            return self.descend(ast.args[0].args[0]), self.descend(ast.args[1])

        elif ast.type == "conditional_statement":
            #if
            if ast.args[0].type == 'if_clause':
                now = self.get_function()
                builder = self.get_builder()
                cond, statement = self.descend(ast.args[0])
                self.counter += 1
                tail = now.append_basic_block("tail_%d" % self.counter)

                # then
                then_block = now.append_basic_block("if_%d" % self.counter)
                self.contexts.append( Context(then_block)  )
                b = self.get_builder()
                b.branch(tail)
                b.position_at_end(tail)
                self.contexts.pop()

                #else
                else_block = None
                if len(ast.args) == 2 and ast.args[1].type == "statement":
                    else_block = now.append_basic_block("else_%d" % self.counter)
                    self.contexts.append( Context(else_block)  )
                    self.descend(ast.args[1])
                    b = self.get_builder()
                    b.branch(tail)
                    b.position_at_end(tail)
                    self.contexts.pop()

                builder.cbranch(cond,then_block,else_block)
                self.contexts[-1].builder = Builder.new(tail)

        elif ast.type == "left_part_list":
            if len(ast.args) == 1:
                return [self.descend( ast.args[0] )]
            else:
                ls = list()
                ls.extend( self.descend(ast.args[0]) )
                ls.append( self.descend(ast.args[1]) )

        elif ast.type == "left_part":
            return self.descend(ast.args[0])

        elif ast.type == "variable":
            return self.get_var( self.descend(ast.args[0]) )

        elif ast.type == "simple_variable":
            return self.descend(ast.args[0])

        elif ast.type == "arithmetic_expression":
            if len(ast.args) == 1:
                return self.descend(ast.args[0])

        elif ast.type == "simple_arithmetic_expression":
            if len(ast.args) == 1:
                return self.term(ast.args[0])
            elif len(ast.args) == 2:
                builder = self.get_builder()
                if ast.args[0].args[0] == "+":
                    return builder.add(c_int(0), self.term(ast.args[1]))
                else:
                    return builder.sub(c_int(0), self.term(ast.args[1]))
            else:
                builder = self.get_builder()
                if ast.args[1].args[0] == "+":
                    return builder.add(self.descend(ast.args[0]), self.term(ast.args[2]))
                else:
                    return builder.sub(self.descend(ast.args[0]), self.term(ast.args[2]))

        #добавляем название переменных и их типы из type_declaration
        elif ast.type == "type_declaration":
            local_or_own_type = ast.args[0]
            if len(local_or_own_type.args) == 1:
                var_type = local_or_own_type.args[0].args[0]
            else:
                var_type = local_or_own_type.args[0].args[0] + local_or_own_type.args[0].args[1]

            builder = self.get_builder()
            type_list = self.flatten(ast.args[1])
            for var_name in type_list:
                v = var_init(builder, var_name.args[0], var_type)
                self.set_var(var_name.args[0], v)


        elif ast.type in ["array_identifier", "variable_identifier", "procedure_identifier", "identifier"]:
            return str(ast.args[0]).lower()


        #присваивание
        elif ast.type == "assignment_statement":
            builder = self.get_builder()
            varName = self.descend(ast.args[0])
            value = self.descend(ast.args[1])
            for v in varName:
                ref = self.get_var(v)
                builder.store(value, ref)
            return varName[0]

        elif ast.type == "identifier_list":
            if len(ast.args) == 1:
                return [ast.args[0]]
            else:
                ls = list()
                ls.extend( self.descend(ast.args[0]) )
                ls.append( ast.args[2] )

        elif ast.type == "type":
            return types.translation[ast.args[0]]

        elif ast.type == "specifier":
            if len(ast.args) == 1:
                return self.descend(ast.args[0])

        elif ast.type == "specification_part":
            if len(ast.args) == 2:
                specifier = self.descend(ast.args[0])
                identifiers = self.descend(ast.args[1])
                return [(specifier, identifiers)]
            else:
                ls = list()
                ls.extend( self.descend(ast.args[0]) )
                ls.append( (self.descend(ast.args[1]), self.descend(ast.args[2]) ) )
                return ls


        #объявление процедур. Храним название процедур(перегрузку запрещаем)
        elif ast.type == "procedure_declaration":
            type = None
            if len(ast.args) > 2:
                type = ast.args[0].args[0]
                heading = ast.args[1]
                body = ast.args[2]
            else:
                heading = ast.args[0]
                body = ast.args[1]

            if not type:
                return_type = types.void
            else:
                return_type = types.translation[type]

            proc_name = heading.args[0].args[0].lower()


            args = list()
            value_part = list()
            specification_part = list()
            if len(heading.args) > 1:
                i = 1
                while i < len(heading.args):
                    if heading.args[i] is not None:
                        if heading.args[i].type == "formal_parameter_part":
                            if len(heading.args[i].args) > 0:
                                formal_parameter = heading.args[i].args[0]
                                if len(formal_parameter.args) > 0:
                                    args = self.flatten(formal_parameter.args[0])
                        elif heading.args[i].type == "value_part":
                            value_part = heading.args[i]
                            if len(value_part.args) > 0:
                                value_part = self.flatten(value_part.args[0])
                        elif heading.args[i].type == "specification_part":
                            specification_part = self.descend(heading.args[i])
                    i += 1

            code = body

            param_types = list()
            for arg in args:
                for type, var_names in specification_part:
                    if arg in var_names:
                        param_types.append(type)
                        break


            ftype = types.function(return_type,param_types)  #типы заранее мы не знаем
            f = Function.new(self.module, ftype, proc_name)
            fb = Builder.new(f.append_basic_block("entry"))

            self.contexts.append(Context( f,fb ))
            b = self.get_builder()
            for i, p in enumerate(args):
                x = f.args[i]
                x.name = p
                self.set_param(p, x)

            type_name = types.reverse_translation[return_type]
            v = var_init(b, proc_name, type_name)
            self.set_var(proc_name,v)
            self.descend(code)
            b = self.get_builder()
            b.ret(b.load(self.get_var(proc_name)))
            self.contexts.pop()


        elif ast.type == "while":
            self.counter += 1
            now = self.get_function()
            builder = self.get_builder()


            loop = now.append_basic_block("loop_%d" % self.counter)            
            body = now.append_basic_block("body_%d" % self.counter)
            tail = now.append_basic_block("tail_%d" % self.counter)

            # do while code
            self.contexts.append(Context(loop))
            b = self.get_builder()
            cond = self.descend(ast.args[0])
            b.cbranch(cond,body,tail)
            self.contexts.pop()

            self.contexts.append(Context(body))
            b = self.get_builder()
            self.descend(ast.args[1])
            # repeat
            b.branch(loop)
            self.contexts.pop()

            # start loop
            builder.branch(loop)
            self.contexts[-1].builder = Builder.new(tail)

        elif ast.type == "repeat":
            cond = Node('not',ast.args[1])
            body = ast.args[0]

            while_b = Node('while',cond,body)
            final = Node('statement_list',body,while_b)
            return self.descend(final)

        elif ast.type == "for":

            direction = self.descend(ast.args[1])
            limit = ast.args[2]
            builder = self.get_builder()

            # var declaration
            varname = self.descend(ast.args[0].args[0])
            vartype = "INTEGER"
            v = var_init(builder, varname, vartype)
            self.set_var(varname,v)

            # var init
            variable = self.descend(ast.args[0])

            # cond
            var1 = Node('element',Node('identifier',varname))
            var1_name = Node('identifier',varname)

            sign = Node('sign',(direction == "to") and '<=' or '>=')
            comp = Node('op',sign,var1,limit)

            # body
            op = Node('sign',(direction == "to") and '+' or '-')
            varvalue = Node('op',op,var1,Node('element',Node('integer',1)))
            increment = Node('assign',var1_name,varvalue)

            body = Node('statement_list',ast.args[3],increment)

            # do while
            while_block = Node('while',comp,body)            

            self.descend(while_block)


        elif ast.type in ["sign","and_or"]:
            return ast.args[0]

        elif ast.type == 'not':
            v = self.descend(ast.args[0])
            builder = self.get_builder()
            return builder.not_(v)


        elif ast.type == "element":
            builder = self.get_builder()

            e = ast.args[0]
            if e.type == "identifier":
                ref = self.get_var(self.descend(e))
                if ref.__class__ == Argument:
                    return ref
                return builder.load(ref)
            else:
                return self.descend(ast.args[0])

        elif ast.type == "string":
            b = self.get_builder()
            s = c_string(self.module,ast.args[0])
            return pointer(b,s)

        elif ast.type == "unsigned_number":
            if len(ast.args) == 1:
                return self.descend(ast.args[0])
            else:
                exp = self.descend(ast.args[1])
                return self.descend(ast.args[0]) * pow(x=10, y=exp)

        elif ast.type == "decimal_number":
            if len(ast.args) == 1:
                return self.descend(ast.args[0])
            else:
                return self.descend(ast.args[0]) + self.descend(ast.args[1])

        elif ast.type == "unsigned_integer":
            if len(ast.args) == 1:
                return c_int(int(ast.args[0]))
            else:
                value = self.descend(ast.args[0]) * 10 + ast.args[1]
                return c_int(int(ast.args[0]))

        elif ast.type == "real":
            return c_real(float(ast.args[0]))

        else:
            print "unknown:", ast.type
            sys.exit()