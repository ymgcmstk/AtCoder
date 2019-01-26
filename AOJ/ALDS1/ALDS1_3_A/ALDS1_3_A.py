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

cur_stack = []
for i in N.split():
    if i == '+':
        cur_stack = cur_stack[:-2] + [cur_stack[-2] + cur_stack[-1]]
    elif i == '-':
        cur_stack = cur_stack[:-2] + [cur_stack[-2] - cur_stack[-1]]
    elif i == '*':
        cur_stack = cur_stack[:-2] + [cur_stack[-2] * cur_stack[-1]]
    else:
        cur_stack.append(int(i))
assert len(cur_stack) == 1
print cur_stack[-1]
