#coding: utf-8
__author__ = 'tural'

class Node(object):
    def __init__(self, t, *args):
        self.type = t
        self.args = args

    def __str__(self):
        s = u"type: %s \n" % self.type
        s += u"".join([u"i: %s \n" % i for i in self.args])
        return s