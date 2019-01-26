# -*- coding:utf-8 -*-
import sys

def split_int(string):
    return [int(x) for x in string.split()]

def get_line(integer=False):
    string = sys.stdin.readline().rstrip()
    if integer:
        return split_int(string)
    else:
        return string

N = get_line()
cur_sum = 0;
for i in N.split('+'):
    if eval(i) > 0:
        cur_sum += 1
print cur_sum
