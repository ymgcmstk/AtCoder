#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *

class Node:
    parent     = None
    right_node = None
    child_node = None
    var        = None
    __name__   = 'Node'
    def __init__(self, var=None, parent=None):
        self.var = var
        self.parent = parent
    def set_right_node(self, right_node):
        self.right_node = right_node
    def set_child_node(self, child_node):
        self.child_node = child_node

def main():
    print Node
    a = Node()
    print type(a)
    print a.parent
    return

if __name__ == '__main__':
    main()
