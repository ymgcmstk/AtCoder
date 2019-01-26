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
cur_sum = 0
for i in range(N):
    A, B = get_line(int)
    cur_sum += A*B
cur_sum = int(1.05 * cur_sum)

print cur_sum
