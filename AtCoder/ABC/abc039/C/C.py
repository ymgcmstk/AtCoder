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

N = get_line()
base_str = 'WBWBWWBWBWBW'
base_str *= 3

a = base_str.find(N)
if a < 2:
    print 'Do'
elif a < 4:
    print 'Re'
elif a < 5:
    print 'Mi'
elif a < 7:
    print 'Fa'
elif a < 9:
    print 'So'
elif a < 11:
    print 'La'
else:
    print 'Si'
