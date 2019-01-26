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

N = get_line(int)
if N == [5, 5, 7] or N == [5, 7, 5] or N == [7, 5, 5]:
    print 'YES'
else:
    print 'NO'
