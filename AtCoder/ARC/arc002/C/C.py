# -*- coding:utf-8 -*-
import sys
from copy import deepcopy as DC

def split_int(string):
    return [int(x) for x in string.split()]

def get_line(integer=False):
    string = sys.stdin.readline().rstrip()
    if integer:
        return split_int(string)
    else:
        return string

I2B = {0:'A', 1:'B', 2:'X', 3:'Y'}
B2I = {j:i for i, j in I2B.iteritems()}

N = int(get_line())
Cs = get_line()

cur_min = N
for i in range(15):
    L = I2B[i / 4] + I2B[i % 4]
    i_Cs = Cs.replace(L, 'L')
    for j in range(i+1, 16):
        R = I2B[j / 4] + I2B[j % 4]
        j_Cs = i_Cs.replace(R, 'R')
        cur_min = min(cur_min, len(j_Cs))
        # print j_Cs, L, R, len(j_Cs)

print cur_min
