#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *

class Node:
    var       = None
    prev_node = None
    next_node = None
    def __init__(self, var=None, prev_node=None, next_node=None):
        self.var = var
        self.prev_node = prev_node
        self.next_node = next_node
    def get_prev_node(self):
        return self.prev_node
    def get_next_node(self):
        return self.next_node

def main():
    return

if __name__ == '__main__':
    main()
