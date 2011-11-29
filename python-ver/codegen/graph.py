#coding: utf-8
__author__ = 'tural'

import pydot
from ast import Node

def graph(node, filename=None):
    edges = descend(node)
    g = pydot.graph_from_edges(edges)
    if filename is not None:
        f = filename + ".png"
    else:
        f = "graph.png"
    g.write(f, prog="dot", format="png")

def descend(node):
    edges = list()
    if not isinstance(node, Node):
        return list()

    for i in node.args:
        edges.append((s(node), s(i)))
        edges += descend(i)
    return edges

def s(node):
    if not isinstance(node, Node):
        return "%s (%s)" % (node, id(node))
    return "%s (%s)" % (node.type, id(node))