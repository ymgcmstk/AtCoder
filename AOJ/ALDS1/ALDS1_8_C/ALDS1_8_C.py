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
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
    def insert_node(self, cur_key):
        if self.key <= cur_key:
            if self.right is None:
                self.right = Node(cur_key)
            else:
                self.right.insert_node(cur_key)
        else:
            if self.left is None:
                self.left = Node(cur_key)
            else:
                self.left.insert_node(cur_key)
    def find_node(self, cur_key):
        if self.key == cur_key:
            print 'yes'
        elif self.key < cur_key:
            if self.right is None:
                print 'no'
            else:
                self.right.find_node(cur_key)
        else:
            if self.left is None:
                print 'no'
            else:
                self.left.find_node(cur_key)
    def delete_node(self, cur_key, par_node, is_left):
        if self.key < cur_key:
            assert self.right is not None
            self.right.delete_node(cur_key, self, False)
            return
        elif self.key > cur_key:
            assert self.left is not None
            self.left.delete_node(cur_key, self, True)
            return
        if self.left is None and self.right is None:
            if is_left:
                par_node.left = None
            else:
                par_node.right = None
            return
        if self.left is None:
            if is_left:
                par_node.left = self.right
            else:
                par_node.right = self.right
            return
        if self.right is None:
            if is_left:
                par_node.left = self.left
            else:
                par_node.right = self.left
            return
        new_node, par_new_node, par_is_left = self.find_new_node(self, True)
        new_node.delete_node(new_node.key, par_new_node, par_is_left)
    def find_new_node(self, par, start=False):
        is_left = True
        if start:
            next_node = self.right
            is_left = False
        else:
            next_node = self.left
        if next_node is None:
            return self, par, is_left
        next_node.find_new_node(self)
    def print_preorder(self):
        print self.key,
        if self.left is not None:
            self.left.print_preorder()
        if self.right is not None:
            self.right.print_preorder()
    def print_inorder(self):
        if self.left is not None:
            self.left.print_inorder()
        print self.key,
        if self.right is not None:
            self.right.print_inorder()


def main():
    N = int(get_line())
    base_node = Node(2000000001)
    for i in range(N):
        cur_line = get_line().split()
        if cur_line[0] == 'insert':
            base_node.insert_node(int(cur_line[1]))
        elif cur_line[0] == 'find':
            base_node.find_node(int(cur_line[1]))
        elif cur_line[0] == 'delete':
            base_node.left.delete_node(int(cur_line[1]), base_node, True)
        elif cur_line[0] == 'print':
            print '',
            base_node.left.print_inorder()
            print
            print '',
            base_node.left.print_preorder()
            print
        else:
            raise Exception()

if __name__ == '__main__':
    main()
