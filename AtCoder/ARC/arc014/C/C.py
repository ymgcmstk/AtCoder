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

N = get_line(int)[0]
S = get_line(str)[0]
s2c = {'R': 0, 'G': 0, 'B': 0}
for i in S:
    s2c[i] += 1
count = 0
for i in 'RGB':
    if s2c[i] % 2 == 1:
        count += 1
print count
