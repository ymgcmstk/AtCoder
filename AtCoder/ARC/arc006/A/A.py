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

A = set(get_line(integer=True))
bonus = int(get_line())
B = get_line(integer=True)

last_diff = 0
same_num = 0
for i in B:
    if i in A:
        same_num += 1
    else:
        last_diff = i

if same_num == 3:
    print 5
elif same_num == 4:
    print 4
elif same_num == 5 and last_diff == bonus:
    print 2
elif same_num == 5:
    print 3
elif same_num == 6:
    print 1
else:
    print 0
