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

N, K = get_line(int)
D = get_line(int)
D = [i for i in range(10) if not i in D]

temp = []
add_flg = False
for i in str(N)[::-1]:
    flg = True
    if add_flg:
        i = str(int(i) + 1)
        if i == '10':
            i = '0'
        else:
            add_flg = False
    for j in D:
        if j >= int(i):
            temp.append(str(j))
            flg = False
            break
    if flg:
        temp.append(str(D[0]))
        add_flg = True

if add_flg:
    for j in D:
        if j >= 1:
            temp.append(str(j))
            break

print ''.join(temp)[::-1]
