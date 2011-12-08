from llvm.core import *

# auxiliary
void = Type.void()
boolean = Type.int(1)
int8 = Type.int(8)

integer = Type.int()
real  = Type.double()
char = Type.int()
string = lambda x: Type.array( integer, x )

function = Type.function

def procedure(*args):
    return Type.function(void, args)


translation = {
    "integer": integer,
    "real": real,
    "string": string,
    "boolean": boolean,
}

class ReverseDict(object):
    def __init__(self,dic):
        self.dic = dic
    def __getitem__(self,p):
        for k in self.dic:
            if self.dic[k] == p:
                return k

reverse_translation = ReverseDict(translation)

defaults = {
    "integer": 0,
    "real": 0.0,
    "string": '',
    "boolean": False,
}