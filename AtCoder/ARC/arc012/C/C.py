# -*- coding:utf-8 -*-
import sys

def split_with_func(string, func):
    return [func(x) for x in string.split()]

def get_line(func=None):
    string = sys.stdin.readline().rstrip()
    if func is not None:
        return split_with_func(string, func)
    else:
        return string

def print_lines(ls):
    for l in ls:
        print l

lines = [get_line() for i in range(19)]
ver_lines = ['' for i in range(19)]
for _, line in enumerate(lines):
    for i, j in enumerate(line):
        ver_lines[i] += j

print_lines(ver_lines)

black = 'o'
white = 'x'
n_b = 0
n_w = 0

for i in lines:
    for j in lines:
        if j == black:
            n_b += 1
        elif j == white:
            n_w += 1

hor_b = [True if 'ooooo' in i else False for i in lines]
hor_w = [True if 'xxxxx' in i else False for i in lines]

ver_b = [True if 'ooooo' in i else False for i in lines]
ver_w = [True if 'xxxxx' in i else False for i in lines]

if n_b < n_w or n_b - 1 > n_w:
    print 'NO'
    exit()

end_b = True
if n_b == n_w:
    end_b = False

if end_b and (True in ver_w or True in hor_w):
    print 'NO'
    exit()

if not end_b and (True in ver_b or True in hor_b):
    print 'NO'
    exit()



print 'YES'
