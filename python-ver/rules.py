#coding: utf-8
__author__ = 'tural'

from codegen.ast import Node
import sys

precedence = (
    ('left', 'PLUS', 'MINUS'),
    ('left', 'TIMES'),
    ('left', 'DIV', 'MOD'),
    ('left', 'EQUIV', 'IMPL', 'OR', 'AND'),
    ('right', 'NOT', 'POWER'),
    ('left', 'LESS', 'NOTGREATER', 'EQUAL', 'NOTEQUAL', 'GREATER', 'NOTLESS'),
)

def p_program(t):
    r"""program : block
                | compound_statement"""
    t[0] = Node("program", t[1])

def p_block(t):
    r"""block   : unlabelled_block
                | TLABEL COLON block"""
    if len(t) == 2:
        t[0] = Node("block", t[1])
    else:
        t[0] = Node("block", t[3])

def p_unlabelled_block(t):
    r"""unlabelled_block : block_head SEMICOLON compound_tail"""
    t[0] = Node("unlabeled_block", t[1], t[3])

def p_block_head(t):
    r"""block_head  : BEGIN declaration
                    | block_head SEMICOLON declaration"""
    if len(t) == 3:
        t[0] = Node("block_head", t[2])
    else:
        t[0] = Node("block_head", t[1], t[3])

def p_compound_statement(t):
    r"""compound_statement  : unlabelled_compound
                            | label COLON compound_statement"""
    if len(t) == 2:
        t[0] = Node("compound_statement", t[1])
    else:
        t[0] = Node("compound_statement", t[1], t[3])

def p_unlabelled_compound(t):
    r"""unlabelled_compound : BEGIN compound_tail"""
    t[0] = Node("compound_statement", t[2])

def p_compound_tail(t):
    r"""compound_tail   : statement END
                        | statement SEMICOLON compound_tail"""
    if len(t) == 3:
        t[0] = Node("compound_tail", t[1])
    else:
        t[0] = Node("compound_tail", t[1], t[3])

def p_declaration(t):
    r"""declaration : type_declaration
                    | array_declaration
                    | switch_declaration
                    | procedure_declaration"""
    t[0] = Node("declaration", t[1])

def p_type_declaration(t):
    r"""type_declaration : local_or_own_type type_list"""
    t[0] = Node("type_declaration", t[1], t[2])

def p_local_or_own_type(t):
    r"""local_or_own_type   : type
                            | TOWN type"""
    if len(t) == 2:
        t[0] = Node("local_or_own_type", t[1])
    else:
        t[0] = Node("local_or_own_type", t[1], t[2])

def p_type(t):
    r"""type    : TREAL
                | TINTEGER
                | TBOOLEAN"""
    t[0] = Node("type",t[1].lower())

def p_type_list(t):
    r"""type_list   : simple_variable
                    | simple_variable COMMA type_list"""
    if len(t) == 2:
        t[0] = Node("type_list", t[1])
    else:
        t[0] = Node("type_list", t[1], t[3])

def p_array_declaration(t):
    r"""array_declaration   : TARRAY array_list
                            | local_or_own_type TARRAY array_list"""
    if len(t) == 3:
        t[0] = Node("array_declaration", t[2])
    else:
        t[0] = Node("array_declaration", t[1], t[3])

def p_array_list(t):
    r"""array_list  : array_segment
                    | array_list COMMA array_segment"""
    if len(t) == 2:
        t[0] = Node("array_list", t[1])
    else:
        t[0] = Node("array_list", t[1], t[3])

def p_array_segment(t):
    r"""array_segment   : array_identifier LBBRACKET bound_pair_list RBBRACKET
                        | array_identifier COMMA array_segment"""
    t[0] = Node("array_segment", t[1], t[3])

def p_array_identifier(t):
    r"""array_identifier : IDENTIFIER"""
    t[0] = Node("array_identifier", t[1])

def p_bound_pair_list(t):
    r"""bound_pair_list : bound_pair
                        |  bound_pair_list COMMA bound_pair"""
    if len(t) == 2:
        t[0] = Node("bound_pair_list", t[1])
    else:
        t[0] = Node("bound_pair_list", t[1], t[3])

def p_bound_pair(t):
    r"""bound_pair : lower_bound COLON upper_bound"""
    t[0] = Node("bound_pair", t[1], t[3])

def p_upper_bound(t):
    r"""upper_bound : arithmetic_expression"""
    t[0] = Node("upper_bound", t[1])

def p_lower_bound(t):
    r"""lower_bound : arithmetic_expression"""
    t[0] = Node("lower_bound", t[1])

def p_switch_declaration(t):
    r"""switch_declaration : SWITCH switch_identifier ASSIGNMENT switch_list"""
    t[0] = Node("switch_declaration", t[2], t[4])

def p_switch_identifier(t):
    r"""switch_identifier : IDENTIFIER"""
    t[0] = Node("switch_identifier", t[1])

def p_switch_list(t):
    r"""switch_list : designational_expression
                    | switch_list COMMA designational_expression"""
    if len(t) == 2:
        t[0] = Node("switch_list", t[1])
    else:
        t[0] = Node("switch_list", t[1], t[3])

def p_procedure_declaration(t):
    r"""procedure_declaration   : PROCEDURE procedure_heading procedure_body
                                | type PROCEDURE procedure_heading procedure_body"""
    if len(t) == 4:
        t[0] = Node("procedure_declaration", t[2], t[3])
    else:
        t[0] = Node("procedure_declaration", t[1], t[3], t[4])

def p_procedure_heading(t):
    r"""procedure_heading : procedure_identifier formal_parameter_part SEMICOLON value_part specification_part"""
    t[0] = Node("procedure_heading", t[1], t[2], t[4], t[5])

def p_procedure_identifier(t):
    r"""procedure_identifier : IDENTIFIER"""
    t[0] = Node("procedure_identifier", t[1])

def p_formal_parameter_part(t):
    r"""formal_parameter_part   :
                                | LCBRACKET formal_parameter_list RCBRACKET"""
    if len(t) > 1:
        t[0] = Node("formal_parameter_part", t[2])

def p_formal_parameter_list(t):
    r"""formal_parameter_list   : formal_parameter
                                | formal_parameter_list parameter_delimiter formal_parameter"""
    if len(t) == 2:
        t[0] = Node("formal_parameter_list", t[1])
    else:
        t[0] = Node("formal_parameter_list", t[1], t[2], t[3])

def p_formal_parameter(t):
    r"""formal_parameter : IDENTIFIER """
    t[0] = Node("formal_parameter", t[1])

def p_value_part(t):
    r"""value_part  :
                    | TVALUE identifier_list SEMICOLON"""
    if len(t) > 1:
        t[0] = Node("value_part", t[2])

def p_specification_part(t):
    r"""specification_part  :
                            | specifier identifier_list SEMICOLON
                            | specification_part specifier identifier_list"""
    if len(t) == 4:
        if t[3] == ';':
            t[0] = Node("specification_part", t[1], t[2])
        else:
            t[0] = Node("specification_part", t[1], t[2], t[3])

def p_specifier(t):
    r"""specifier   : TSTRING
                    | type
                    | TARRAY
                    | type TARRAY
                    | TLABEL
                    | SWITCH
                    | PROCEDURE
                    | type PROCEDURE"""
    t[0] = Node("specifier", t[1])

def p_identifier_list(t):
    r"""identifier_list : IDENTIFIER
                        | identifier_list COMMA IDENTIFIER"""
    if len(t) == 2:
        t[0] = Node("identifier_list", t[1])
    else:
        t[0] = Node("identifier_list", t[1], t[3])

def p_procedure_body(t):
    r"""procedure_body : statement"""
    t[0] = Node("statement", t[1])

def p_statement(t):
    r"""statement   : unconditional_statement
                    | conditional_statement
                    | for_statement"""
    t[0] = Node("statement", t[1])

def p_unconditional_statement(t):
    r"""unconditional_statement : basic_statement
                                | compound_statement
                                | block"""
    t[0] = Node("unconditional_statement", t[1])

def p_basic_statement(t):
    r"""basic_statement : unlabelled_basic_statement
                        | label COLON basic_statement"""
    if len(t) == 2:
        t[0] = Node("basic_statement", t[1])
    else:
        t[0] = Node("basic_statement", t[1], t[3])

def p_label(t):
    r"""label   : IDENTIFIER
                | unsigned_integer"""
    t[0] = Node("label", t[1])

def p_unlabelled_basic_statement(t):
    r"""unlabelled_basic_statement  : assignment_statement
                                    | go_to_statement
                                    | procedure_statement"""
    if len(t) > 1:
        t[0] = Node("unlabelled_basic_statement", t[1])

def p_assignment_statement(t):
    r"""assignment_statement    : left_part_list arithmetic_expression
                                | left_part_list boolean_expression"""
    t[0] = Node("assignment_statement", t[1], t[2])

def p_left_part_list(t):
    r"""left_part_list  : left_part
                        | left_part_list left_part"""
    if len(t) == 2:
        t[0] = Node("left_part_list", t[1])
    else:
        t[0] = Node("left_part_list", t[1], t[2])

def p_left_part(t):
    r"""left_part   : variable ASSIGNMENT
                    | procedure_identifier ASSIGNMENT"""
    t[0] = Node("left_part", t[1])

def p_go_to_statement(t):
    r"""go_to_statement : GOTO designational_expression"""
    t[0] = Node("go_to_statement", t[2])

def p_designational_expression(t):
    r"""designational_expression    : simple_designational_expression
                                    | if_clause simple_designational_expression ELSE designational_expression"""
    if len(t) == 2:
        t[0] = Node("designational_expression", t[1])
    else:
        t[0] = Node("designational_expression", t[1], t[2], t[4])

def p_simple_designational_expression(t):
    r"""simple_designational_expression : label
                                        | switch_designator
                                        | LCBRACKET designational_expression RCBRACKET"""
    if len(t) == 2:
        t[0] = Node("simple_designational_expression", t[1])
    else:
        t[0] = Node("simple_designational_expression", t[2])

def p_switch_designator(t):
    r"""switch_designator : switch_identifier LBBRACKET subscript_expression RBBRACKET"""
    t[0] = Node("switch_designator", t[1], t[2])

def p_procedure_statement(t):
    r"""procedure_statement : procedure_identifier actual_parameter_part"""
    t[0] = Node("procedure_statement", t[1], t[2])

def p_actual_parameter_part(t):
    r"""actual_parameter_part   : LCBRACKET RCBRACKET
                                | LCBRACKET actual_parameter_list RCBRACKET"""
    if len(t) > 2:
        t[0] = Node("actual_parameter_part", t[2])

def p_actual_parameter_list(t):
    r"""actual_parameter_list   : actual_parameter
                                | actual_parameter_list parameter_delimiter actual_parameter"""
    if len(t) == 2:
        t[0] = Node("actual_parameter_list", t[1])
    else:
        t[0] = Node("actual_parameter_list", t[1], t[2], t[3])

def p_parameter_delimiter(t):
    r"""parameter_delimiter : COMMA
                            | RCBRACKET letter_string COLON LCBRACKET"""
    if len(t) > 2:
        t[0] = Node("parameter_delimiter", t[2])

def p_actual_parameter(t):
    r"""actual_parameter    : string
                            | expression
                            | array_identifier
                            | switch_identifier
                            | procedure_identifier"""
    t[0] = Node("actual_parameter", t[1])

def p_conditional_statement(t):
    r"""conditional_statement   : if_statement
                                | if_statement ELSE statement
                                | if_clause for_statement
                                | label COLON conditional_statement"""
    if len(t) == 2:
        t[0] = Node("conditional_statement", t[1])
    elif len(t) == 3:
        t[0] = Node("conditional_statement", t[1], t[2])
    else:
        t[0] = Node("conditional_statement", t[1], t[3])

def p_if_statement(t):
    r"""if_statement : if_clause unconditional_statement"""
    t[0] = Node("if_statement", t[1], t[2])

def p_if_clause(t):
    r"""if_clause : IF boolean_expression THEN"""
    t[0] = Node("if_clause", t[2])

def p_for_statement(t):
    r"""for_statement   : for_clause statement
                        | label COLON for_statement"""
    if len(t) == 3:
        t[0] = Node("for_statement", t[1], t[2])
    else:
        t[0] = Node("for_statement", t[1], t[3])

def p_for_clause(t):
    r"""for_clause : FOR variable ASSIGNMENT for_list DO"""
    t[0] = Node("for_clause", t[2], t[4])

def p_for_list(t):
    r"""for_list    : for_list_element
                    | for_list COMMA for_list_element"""
    if len(t) == 2:
        t[0] = Node("for_list", t[1])
    else:
        t[0] = Node("for_list", t[1], t[3])

def p_for_list_element(t):
    r"""for_list_element    : arithmetic_expression
                            | arithmetic_expression STEP arithmetic_expression UNTIL arithmetic_expression
                            | arithmetic_expression WHILE boolean_expression"""
    if len(t) == 2:
        t[0] = Node("for_list_element", t[1])
    elif len(t) == 4:
        t[0] = Node("for_list_element", t[1], t[3])
    else:
        t[0] = Node("for_list_element", t[1], t[3], t[5])

def p_expression(t):
    r"""expression  : arithmetic_expression
                    | boolean_expression
                    | designational_expression"""
    t[0] = Node("expression", t[1])

def p_arithmetic_expression(t):
    r"""arithmetic_expression   : simple_arithmetic_expression
                                | if_clause simple_arithmetic_expression ELSE arithmetic_expression"""
    if len(t) == 2:
        t[0] = Node("arithmetic_expression", t[1])
    else:
        t[0] = Node("arithmetic_expression", t[1], t[2], t[4])

def p_simple_arithmetic_expression(t):
    r"""simple_arithmetic_expression    : term
                                        | adding_operator term
                                        | simple_arithmetic_expression adding_operator term"""
    if len(t) == 2:
        t[0] = Node("simple_arithmetic_expression", t[1])
    elif len(t) == 3:
        t[0] = Node("simple_arithmetic_expression", t[1], t[2])
    else:
        t[0] = Node("simple_arithmetic_expression", t[1], t[2], t[3])

def p_adding_operator(t):
    r"""adding_operator : PLUS
                        | MINUS"""
    t[0] = Node("adding_operator", t[1])

def p_term(t):
    r"""term    : factor
                | term multiplying_operator factor"""
    if len(t) == 2:
        t[0] = Node("term", t[1])
    else:
        t[0] = Node("term", t[1], t[2], t[3])

def p_multiplying_operator(t):
    r"""multiplying_operator    : TIMES
                                | DIV
                                | MOD"""
    t[0] = Node("multiplying_operator", t[1])

def p_factor(t):
    r"""factor  : primary
                | factor
                | factor POWER primary"""
    if len(t) == 2:
        t[0] = Node("factor", t[1])
    else:
        t[0] = Node("factor", t[1], t[3])

def p_primary(t):
    r"""primary : unsigned_number
                | variable
                | function_designator
                | LCBRACKET arithmetic_expression RCBRACKET"""
    if len(t) == 2:
        t[0] = Node("primary", t[1])
    else:
        t[0] = Node("primary", t[2])


def p_unsigned_number(t):
    r"""unsigned_number : decimal_number
                        | exponential_part
                        | decimal_number exponential_part"""
    if len(t) == 2:
        t[0] = Node("unsigned_number", t[1])
    else:
        t[0] = Node("unsigned_number", t[1], t[2])


def p_decimal_number(t):
    r"""decimal_number  : unsigned_integer
                        | decimal_fraction
                        | unsigned_integer decimal_fraction"""
    if len(t) == 2:
        t[0] = Node("decimal_number", t[1])
    else:
        t[0] = Node("decimal_number", t[1], t[2])

def p_unsigned_integer(t):
    r"""unsigned_integer    : DIGIT
                            | unsigned_integer DIGIT"""
    if len(t) > 2:
        t[0] = Node("unsigned_integer", t[1], t[2])
    else:
        t[0] = Node("unsigned_integer", t[1])

def p_decimal_fraction(t):
    r"""decimal_fraction : DOT unsigned_integer"""
    t[0] = Node("decimal_fraction", t[2])

def p_exponential_part(t):
    r"""exponential_part : EREAL integer"""
    t[0] = Node("exponential_part", t[2])

def p_integer(t):
    r"""integer : unsigned_integer
                | PLUS unsigned_integer
                | MINUS unsigned_integer"""
    if len(t) == 2:
        t[0] = Node("integer", t[1])
    else:
        t[0] = Node("integer", t[2])

def p_boolean_expression(t):
    r"""boolean_expression  : simple_boolean
                            | if_clause simple_boolean ELSE boolean_expression"""
    if len(t) == 2:
        t[0] = Node("boolean_expression", t[1])
    else:
        t[0] = Node("boolean_expression", t[1], t[2], t[4])

def p_simple_boolean(t):
    r"""simple_boolean  : implication
                        | simple_boolean EQUIV implication"""
    if len(t) == 2:
        t[0] = Node("simple_boolean", t[1])
    else:
        t[0] = Node("simple_boolean", t[1], t[3])

def p_implication(t):
    r"""implication : boolean_term
                    | implication IMPL boolean_term"""
    if len(t) == 2:
        t[0] = Node("implication", t[1])
    else:
        t[0] = Node("implication", t[1], t[3])

def p_boolean_term(t):
    r"""boolean_term    : boolean_factor
                        | boolean_term OR boolean_factor"""
    if len(t) == 2:
        t[0] = Node("boolean_term", t[1])
    else:
        t[0] = Node("boolean_term", t[1], t[3])

def p_boolean_factor(t):
    r"""boolean_factor  : boolean_secondary
                        | boolean_factor AND boolean_secondary"""
    if len(t) == 2:
        t[0] = Node("boolean_factor", t[1])
    else:
        t[0] = Node("boolean_factor", t[1], t[3])

def p_boolean_secondary(t):
    r"""boolean_secondary   : boolean_primary
                            | NOT boolean_primary"""
    if len(t) == 2:
        t[0] = Node("boolean_secondary", t[1])
    else:
        t[0] = Node("boolean_secondary", t[1], t[2])

def p_boolean_primary(t):
    r"""boolean_primary : logical_value
                        | variable
                        | function_designator
                        | relation
                        | LCBRACKET boolean_expression RCBRACKET"""
    if len(t) == 2:
        t[0] = Node("boolean_primary", t[1])
    else:
        t[0] = Node("boolean_primary", t[2])

def p_relation(t):
    r"""relation : simple_arithmetic_expression relational_operator simple_arithmetic_expression"""
    t[0] = Node("relation", t[1], t[2], t[3])

def p_function_designator(t):
    r"""function_designator : procedure_identifier actual_parameter_part"""
    t[0] = Node("function_designator", t[1], t[2])

def p_variable(t):
    r"""variable    : simple_variable
                    | subscripted_variable"""
    t[0] = Node("variable", t[1])

def p_simple_variable(t):
    r"""simple_variable : variable_identifier"""
    t[0] = Node("simple_variable", t[1])

def p_variable_identifier(t):
    r"""variable_identifier : IDENTIFIER"""
    t[0] = Node("variable_identifier", t[1])

def p_subscripted_variable(t):
    r"""subscripted_variable : array_identifier LBBRACKET subscript_list RBBRACKET"""
    t[0] = Node("subscripted_variable", t[1], t[3])

def p_subscript_list(t):
    r"""subscript_list  : subscript_expression
                        | subscript_list COMMA subscript_expression"""
    if len(t) == 2:
        t[0] = Node("subscript_list", t[1])
    else:
        t[0] = Node("subscript_list", t[1], t[3])

def p_subscript_expression(t):
    r"""subscript_expression : arithmetic_expression"""
    t[0] = Node("subscript_expression", t[1])

def p_string(t):
    r"""string : STRING"""
    t[0] = Node("string", t[1])

def p_letter_string(t):
    r"""letter_string   : LETTER
                        | letter_string LETTER"""
    if len(t) > 2:
        t[0] = Node("letter_string", t[1])

def p_logical_value(t):
    r"""logical_value   : TRUE
                        | FALSE"""
    t[0] = Node("logical_value", t[1].lower()),

def p_relational_operator(t):
    r"""relational_operator : LESS
                            | NOTGREATER
                            | EQUAL
                            | NOTLESS
                            | GREATER
                            | NOTEQUAL"""
    t[0] = Node("relational_operator", t[1].lower())


def p_error(t):
    print "Syntax error in input, in line %d" % t.lineno
    sys.exit()

