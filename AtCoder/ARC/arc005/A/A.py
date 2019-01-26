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
words = get_line().split()
if words[-1].endswith('.'):
    words[-1] = words[-1][:-1]
ans = 0

for i in words:
    if i == 'TAKAHASHIKUN':
        ans += 1
    elif i == 'Takahashikun':
        ans += 1
    elif i == 'takahashikun':
        ans += 1
print ans
