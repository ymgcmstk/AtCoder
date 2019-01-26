#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *

class Queue:
    _queue = None
    def __init__(self, queue=[]):
        self._queue = queue
    def enqueue(self, var):
        if len(self._queue) > 0:
            if not isinstance(var, self._queue[0]):
                raise Exception()
        self._queue.append(var)
    def dequeue(self):
        if len(self._queue) == 0:
            raise Exception()
        temp_var = self._queue[0]
        # self._queue = self._queue[1:]
        del self._queue[0]
        return temp_var
    def size(self):
        return len(self._queue)
    def isEmpty(self):
        return self.size() == 0
    def erase(self):
        self._queue = []

class Stack(list):
    def push(self, var):
        self.append(var)


def main():
    A = Stack([3,4])
    print A
    A.pop()
    print A
    A.push(3)
    print A
    return

if __name__ == '__main__':
    main()
