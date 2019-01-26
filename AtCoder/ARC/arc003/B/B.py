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

N = int(get_line())

word_list = []

for i in range(N):
    word_list.append(get_line()[::-1])

for targ_str in sorted(word_list):
    print targ_str[::-1]
