#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *
from math import log
def main():
    line = textread('input.txt')[0]
    cur_sum = -1
    last_zero = -1
    cur_max = -1
    cur_ind = -1
    ADJ = 13
    for i in range(len(line)):
        if float(line[i]) == 0:
            last_zero = i
            cur_sum = 1
            continue
        cur_sum *= float(line[i])
        if i - last_zero >= ADJ + 1:
            cur_sum /= float(line[i-ADJ])
        if cur_sum > cur_max and i - last_zero >= ADJ:
            cur_ind = i
            cur_max = cur_sum
    ans = 1
    for i in range(ADJ):
        ans *= float(line[i-cur_ind])
    print cur_ind, cur_max, ans
    return

if __name__ == '__main__':
    main()
