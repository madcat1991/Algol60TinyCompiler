#coding: utf-8
__author__ = 'tural'


import sys, os
from subprocess import Popen, PIPE

from ply import yacc, lex

from tokens import *
from rules import *
from semantic import *
from codegen.graph import graph
from codegen.builder import *


def get_input(file=None):
#    if file:
#        f = open(file, "r")
#        data = f.read()
#        f.close()
#    else:
#        data = ""
#        while True:
#            try:
#                data += raw_input() + "\n"
#            except :
#                break
    f = open("../common/example.alg", "r")
    data = f.read()
    f.close()
    return data

def main(options=dict(), filename=None):
    logger = yacc.NullLogger()
    yacc.yacc(debug=logger, errorlog=logger)
    yacc.yacc()

    data = get_input(filename)
    ast = yacc.parse(data, lexer=lex.lex(debug=1))

    if options.has_key("graph"):
        graph(ast)

    try:
        check(ast)
    except Exception, e:
        print "Error in semantic: %s", e
        sys.exit()

    try:
        o = Writer()(ast)
    except Exception, e:
        print "Error in builder: %s", e
        sys.exit()

    if not hasattr(o, "ptr"):
        print "Error compiling"
        sys.exit()
        
if __name__ == "__main__":
    main()