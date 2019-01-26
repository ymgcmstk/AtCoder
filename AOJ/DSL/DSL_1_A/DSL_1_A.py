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
        self.par = None
        self.height = 0
    def add_par(self, par):
        self.par = par
        self.par.height = max(self.par.height, self.height + 1)

def main():
    N, COM = get_line(True)
    nodes = []
    for i in range(N):
        nodes.append(Node(i))
    for i in range(COM):
        com, x, y = get_line(True)
        cur_x = nodes[x]
        while cur_x.par is not None:
            cur_x = cur_x.par
        cur_y = nodes[y]
        while cur_y.par is not None:
            cur_y = cur_y.par
        if com == 0:
            if cur_x.height < cur_y.height:
                cur_x.add_par(cur_y)
            else:
                cur_y.add_par(cur_x)
        elif com == 1:
            if cur_x.key == cur_y.key:
                print 1
            else:
                print 0
        else:
            raise Exception()
if __name__ == '__main__':
    main()
