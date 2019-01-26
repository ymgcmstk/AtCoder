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

S1 = set(get_line(int))
S2 = set(get_line(int))
if len(S1 & S2) > 0:
    print 'YES'
else:
    print 'NO'
