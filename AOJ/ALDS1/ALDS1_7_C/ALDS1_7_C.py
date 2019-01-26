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
    def __init__(self, ind, left, right):
        self.ind = ind
        self.left = left
        self.right = right
        self.par = -1
    def set_par(self, par):
        self.par = par

def preorder(node_list, cur_root):
    print node_list[cur_root].ind,
    if node_list[cur_root].left >= 0:
        preorder(node_list, node_list[cur_root].left)
    if node_list[cur_root].right >= 0:
        preorder(node_list, node_list[cur_root].right)

def inorder(node_list, cur_root):
    if node_list[cur_root].left >= 0:
        inorder(node_list, node_list[cur_root].left)
    print node_list[cur_root].ind,
    if node_list[cur_root].right >= 0:
        inorder(node_list, node_list[cur_root].right)

def postorder(node_list, cur_root):
    if node_list[cur_root].left >= 0:
        postorder(node_list, node_list[cur_root].left)
    if node_list[cur_root].right >= 0:
        postorder(node_list, node_list[cur_root].right)
    print node_list[cur_root].ind,

def main():
    N = int(get_line())
    node_list = range(N)
    for i in range(N):
        ind, left, right = get_line(integer=True)
        node_list[ind] = Node(ind, left, right)
    for i in range(N):
        if node_list[i].left >= 0:
            node_list[node_list[i].left].set_par(i)
        if node_list[i].right >= 0:
            node_list[node_list[i].right].set_par(i)
    cur_root = -1
    for i in range(N):
        if node_list[i].par == -1:
            assert cur_root == -1
            cur_root = i
    assert cur_root >= 0
    print 'Preorder'
    print '',
    preorder(node_list, cur_root)
    print
    print 'Inorder'
    print '',
    inorder(node_list, cur_root)
    print
    print 'Postorder'
    print '',
    postorder(node_list, cur_root)

if __name__ == '__main__':
    main()
