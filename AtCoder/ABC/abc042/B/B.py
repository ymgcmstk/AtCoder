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

a, b = get_line(int)
print ''.join(sorted([get_line() for _ in range(a)]))

# print ''.join(sorted(get_line()))
