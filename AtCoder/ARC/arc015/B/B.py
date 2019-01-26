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

ans = [0 for _ in range(6)]

for i in range(N):
    a, b = get_line().split()
    a = float(a)
    b = float(b)
    if a >= 35:
        ans[0] += 1
    elif a >= 30:
        ans[1] += 1
    elif a >= 25:
        ans[2] += 1
    elif a < 0:
        ans[5] += 1
    if b >= 25:
        ans[3] += 1
    if a >= 0 and b < 0:
        ans[4] += 1

count = 0
for i in ans:
    count += 1
    if count == 6:
        print i
    else:
        print i,
