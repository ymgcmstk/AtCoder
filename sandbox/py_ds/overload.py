#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *

class Array:
    _self_list = None
    _temp = 0
    def __init__(self, input_list=[]):
        self._self_list = input_list
    def __add__(self, other):
        return Array(map(lambda x, y:x+y,
                         self._self_list,
                         other._self_list))
    def __str__(self):
        return str(self._self_list)
    def __getitem__(self, key):
        return self._self_list[key]
    def __setitem__(self, key, value):
        self._self_list[key] = value
    def __iter__(self):
        return self
    def __next__(self):
        # raise Exception()
        self._temp += 1
        if self._temp == len(self._self_list) + 1:
            self._temp = 0
            raise StopIteration
        return self._self_list[self._temp - 1]
    def next(self):
        return self.__next__()
    @property
    def x(self):
        return self._x
    @x.setter
    def x(self, temp):
        print temp
        self._x = temp
    @x.getter
    def x(self):
        return self._x
    @x.deleter
    def x(self):
        print self.x
        del self._x

def main():
    A = Array([1, 2])
    B = Array([3, 3])
    C = A + B
    print C
    print C[0]
    C[0] = 1
    print C
    print "Iter test"
    for num, i in enumerate(C):
        print num, ':', i

    print 'About Setter'
    print C.x = 1

    return

if __name__ == '__main__':
    main()
