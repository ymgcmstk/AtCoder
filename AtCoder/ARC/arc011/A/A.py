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

m, n, N = get_line(int)
ans = N
being_used = N
cur = 0
while being_used + cur >= m:
    cur += being_used
    next_p = n * (cur / m)
    cur %= m
    being_used = next_p
    ans += next_p
print ans
