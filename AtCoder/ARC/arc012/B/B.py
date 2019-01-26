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

N, va, vb, L = get_line(int)
va = float(va)
vb = float(vb)
cur_p = float(L)
for _ in range(N):
    cur_p = cur_p / va * vb
if cur_p < 1e-10:
    cur_p = 0
print cur_p
