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

N = get_line(integer=True)
stack = []
for i in range(N[1]):
    stack.append(get_line())

o_cur = len(get_line()) / 2

for i in range(N[1]):
    cur_line = stack[-1]
    cur_line = cur_line.split('|')
    if cur_line[o_cur] == '-':
        o_cur -= 1
    elif cur_line[o_cur+1] == '-':
        o_cur += 1
    del stack[-1]

print o_cur + 1
