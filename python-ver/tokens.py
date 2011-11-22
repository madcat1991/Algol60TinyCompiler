#coding: utf-8
QUOTE = r'(\'|\`)'

tokens = (
    #общее
    'IDENTIFIER',

    #разделители
    'ASSIGNMENT',
    'SEMICOLON',
    'COLON',
    'COMMA',
    'DOT',
    'EREAL',    #1E-4
    'UNDERLINE',
    'STEP',
    'WHILE',
    'UNTIL',
    'COMMENT',

    #границы
    'BEGIN',
    'END',
    'LCBRACKET',    #(
    'RCBRACKET',    #)
    'LBBRACKET',    #[
    'RBBRACKET',    #]

    #деклараторы
    'REAL',
    'INTEGER',
    'BOOLEAN',
    'PROCEDURE',
    'SWITCH',

    #типы данных
    'TOWN',
    'TREAL',
    'TINTEGER',
    'TBOOLEAN',
    'TARRAY',

    #спецификатор
    'LABEL',
    'STRING',
    'VALUE',

    #управление
    'GOTO',
    'IF',
    'ELSE',
    'THEN',
    'FOR',
    'DO',

    #логические
    'EQUIV',
    'IMPL',
    'OR',
    'AND',
    'NOT',

    #булевское
    'TRUE',
    'FALSE',

    #арифметические
    'PLUS',
    'MINUS',
    'TIMES',
    'DIV',
    'MOD',
    'POWER',

    #сравнение
    'LESS',
    'NOTGREATER',
    'EQUAL',
    'NOTLESS',
    'GREATER',
    'NOTEQUAL',
)

#разделители
t_ASSIGNMENT = r":="
t_SEMICOLON = r";"
t_COLON = r":"
t_COMMA = r","
t_DOT = r"\."
t_DQUOTE = r"\""
t_EREAL = r"E"    #1E-4
t_UNDERLINE = r"_"

t_LCBRACKET = r"\("  #(
t_RCBRACKET = r"\)"   #)
t_LBBRACKET = r"\["  #[
t_RBBRACKET = r"\]"  #]

#арифметические
t_PLUS = r"\+"
t_MINUS = r"\-"
t_TIMES = r"\*"
t_DIV = r"\\"
t_MOD = r"\%"
t_POWER = r"\^"

#сравнение
t_LESS = r"\<"
t_NOTGREATER = r"\<\="
t_EQUAL = r"\="
t_NOTLESS = r"\>\="
t_GREATER = r"\>"
t_NOTEQUAL = r"\<\>"

t_REAL = r"(\-)*[0-9]+\.[0-9]+"
t_INTEGER = r"(\-)*[0-9]+"
t_BOOLEAN = r"TRUE|FALSE"
t_ANY_SYMBOL_SEQ_WO_QUOTE = r"[^\"]*"

reserved_keywords = {
#общее
    #разделители
    'step':'STEP',
    'while':'WHILE',
    'until':'UNTIL',
    'commemt':'COMMENT',

    #границы
    'begin':'BEGIN',
    'end':'END',

    #деклараторы
    'own':'TOWN',
    'real':'TREAL',
    'integer':'TINTEGER',
    'Boolean':'TBOOLEAN',
    'array':'TARRAY',
    'procedure':'PROCEDURE',
    'switch':'SWITCH',

    #спецификатор
    'label':'LABEL',
    'string':'STRING',
    'value':'VALUE',

    #управление
    'goto':'GOTO',
    'if':'IF',
    'else':'ELSE',
    'then':'THEN',
    'for':'FOR',
    'do':'DO',

    #логические
    'equiv':'EQUIV',
    'impl':'IMPL',
    'or':'OR',
    'and':'AND',
    'not':'NOT',

    #арифметические
    'power':'POWER',

    #сравнение
    'less': 'LESS',
    'notgreater':'NOTGREATER',
    'equal':'EQUAL',
    'notless':'NOTLESS',
    'greater':'GREATER',
    'notequal':'NOTEQUAL',

    'true': 'TRUE',
    'false': 'FALSE',
}

#общее
def t_IDENTIFIER(t):
    r"""[a-zA-Z]([a-zA-Z])*"""
    if t.value.lower() in reserved_keywords:
        t.type = reserved_keywords[t.value.lower()]
    return t

def t_COMMENT(t):
    r"""comment\s[^\;]*\;"""

#спецификатор
def t_STRING(t):
    r"""(\'([^\\\']|(\\.))*\')|(\`([^\\\']|(\\.))*\`)"""
    escaped = 0
    str = t.value[1:-1]
    new_str = ""
    for i in range(0, len(str)):
        ch = str[i]
        if escaped:
            if ch == "n":
                ch = "\n"
            elif ch == "t":
                ch = "\t"
            new_str += ch
            escaped = 0
        else:
            if ch == "\\":
                escaped = 1
            else:
                new_str += ch
    t.value = new_str
    return t

def t_newline(t):
    r"""\n+"""
    t.lexer.lineno += len(t.value)

t_ignore = ' \t'

def t_error(t):
    print u"Недопустимый символ %s" % t.value[0]


if __name__ == "__main__":
    from ply import lex
    import sys

    lex.lex()
#    if len(sys.argv) > 1:
#        f = open(sys.argv[1], "r")
#        data = f.read()
#        f.close()
#    else:
#        data = ""
#        while True:
#            try:
#                data += raw_input() + "\n"
#            except:
#                break


    f = open("../example.alg", "r")
    data = f.read()
    f.close()

    lex.input(data)

    #Tokenize
    while True:
        tok = lex.token()
        if not tok:
            break
        print tok