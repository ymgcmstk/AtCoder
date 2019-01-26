# -*- coding:utf-8 -*-
import sys

def split_int(string):
    return [int(x) for x in string.split()]

def get_line(integer=False):
    string = sys.stdin.readline().rstrip()
    if interger:
        return split_int(string)
    else:
        return string

N, L = split_int(get_line())
G = split_int(get_line())[0]
