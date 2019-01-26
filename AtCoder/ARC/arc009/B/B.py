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

replacer = {str(i):str(num) for num, i in enumerate(get_line(str))}

N = get_line(int)[0]

replaced = []

for _ in range(N):
    temp = get_line()
    temp2 = ''
    for cur_char in temp:
        temp2 += replacer[cur_char]
    replaced.append((int(temp2), int(temp)))

for _, i in sorted(replaced, key=lambda x: x[0]):
    print i
