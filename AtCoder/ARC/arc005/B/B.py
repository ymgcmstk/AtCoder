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

def get_next(x, y, O):
    next_x = x
    next_y = y
    if 'L' in O:
        next_x = x - 1
        if next_x == -1:
            next_x = 1
            O = O.replace('L', 'R')
    if 'R' in O:
        next_x = x + 1
        if next_x == 9:
            next_x = 7
            O = O.replace('R', 'L')
    if 'U' in O:
        next_y = y - 1
        if next_y == -1:
            next_y = 1
            O = O.replace('U', 'D')
    if 'D' in O:
        next_y = y + 1
        if next_y == 9:
            next_y = 7
            O = O.replace('D', 'U')
    return next_x, next_y, O

Ns = get_line().split()
x = int(Ns[0])-1
y = int(Ns[1])-1
O = Ns[-1]
words = []
for i in range(9):
    words.append(get_line())

ans = words[y][x]
for i in range(3):
    x, y, O = get_next(x, y, O)
    ans += words[y][x]

print ans
