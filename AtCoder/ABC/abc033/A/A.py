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
P = set()
for i in N:
    P.add(i)

if len(P) == 1:
    print "SAME"
else:
    print "DIFFERENT"
