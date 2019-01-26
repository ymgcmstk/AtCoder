# -*- coding:utf-8 -*-
import sys

def split_int(string):
    return [int(x) for x in string.split()]

def get_line(integer=False):
    string = sys.stdin.readline().rstrip()
    if integer:
        return split_int(string)
    else:
        return string

class Node(object):
    def __init__(self, key, next_node):
        self._key = key
        self._next_node = next_node
    def get_key(self):
        return self._key
    def get_next_node(self):
        return self._next_node
    def set_key(self, key):
        self._key = key
    def set_next_node(self, cur_node):
        self._next_node = cur_node

def main():
    last_node = Node(None, None)
    first_node = Node(None, last_node)
    N = int(get_line())
    for i in range(N):
        cur_line = get_line().split()
        if cur_line[0] == 'insert':
            cur_node = Node(int(cur_line[1]), first_node.get_next_node())
            first_node.set_next_node(cur_node)
        if cur_line[0] == 'delete':
            prev_node = first_node
            cur_node = first_node.get_next_node()
            while cur_node.get_key() != int(cur_line[1]):
                prev_node = cur_node
                cur_node = cur_node.get_next_node()
                assert cur_node is not None
            prev_node.set_next_node(cur_node.get_next_node())
        if cur_line[0] == 'deleteFirst':
            first_node.set_next_node(first_node.get_next_node().get_next_node())
        if cur_line[0] == 'deleteLast':
            # TODO
            prev_node = first_node
            cur_node = first_node.get_next_node()
            while cur_node.get_next_node().get_next_node() is not None:
                prev_node = cur_node
                cur_node = cur_node.get_next_node()
            prev_node.set_next_node(cur_node.get_next_node())
    cur_node = first_node.get_next_node()
    while cur_node.get_next_node() is not None:
        print cur_node.get_key(),
        cur_node = cur_node.get_next_node()

if __name__ == '__main__':
    main()
