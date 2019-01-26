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

BASE = get_line()
N = int(get_line())
for i in range(N):
    Q = get_line()
    if Q in BASE:
        print 1
    else:
        print 0
