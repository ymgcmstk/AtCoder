# -*- coding:utf-8 -*-
import sys

def split_with_func(string, func):
    return [func(x) for x in string.split()]

def get_line(func=None):
    string = sys.stdin.readline().rstrip()
    if func is not None:
        return split_with_func(string, func)
    else:
        return string

N, M, A, B = get_line(int)
for i in range(M):
    if N <= A:
        N += B
    N -= get_line(int)[0]
    if N < 0:
        print i + 1
        exit()

print 'complete'
