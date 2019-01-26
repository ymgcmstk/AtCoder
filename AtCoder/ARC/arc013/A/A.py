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

Ns = get_line(int)
Bs = get_line(int)
cur_m = 0

def ret_max(cur_ind):
    if len(cur_ind) == len(Bs):
        cur_i = 1
        for i in range(len(cur_ind)):
            cur_i *= (Ns[i] / Bs[cur_ind[i]])
        return cur_i
    cur_m = 0
    for i in range(3):
        if not i in cur_ind:
            cur_m = max(ret_max(cur_ind + [i]), cur_m)
    return cur_m

print ret_max([])
