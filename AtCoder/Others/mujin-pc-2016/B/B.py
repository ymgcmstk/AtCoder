# -*- coding:utf-8 -*-
import sys
import math

def split_int(string):
    return [int(x) for x in string.split()]

def get_line(integer=False):
    string = sys.stdin.readline().rstrip()
    if integer:
        return split_int(string)
    else:
        return string

a, b, c = get_line(integer=True)

cur_sum = a + b + c
cur_max = max(max(a, b), c)
cur_temp = max(cur_max - (cur_sum - cur_max), 0)

ans = cur_sum * cur_sum * math.pi - cur_temp * cur_temp * math.pi

print ans
