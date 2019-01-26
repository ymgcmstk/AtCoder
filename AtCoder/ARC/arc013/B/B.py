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

C = get_line(int)[0]
Bs = [sorted(get_line(int)) for _ in range(C)]

ans = [max([b[i] for b in Bs]) for i in range(3)]
a = 1
for i in ans:
    a *= i
print a
