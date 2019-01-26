#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *
set_debugger(send_email=False, error_func=None)
import random
import copy
NUM = 100


def quick_sort(num_list, start, end):
    if end - start <= 1:
        return
    if end - start == 2:
        if num_list[end-1] < num_list[start]:
            num_list[end-1], num_list[start] = num_list[start], num_list[end-1]
        return
    piv = num_list[start]
    cur_ind = start + 1
    cur_cent = start + 1
    while cur_ind < end:
        if piv > num_list[cur_ind]:
            num_list[cur_ind], num_list[cur_cent] = num_list[cur_cent], num_list[cur_ind]
            cur_cent += 1
        cur_ind += 1
    cur_cent -= 1
    num_list[start], num_list[cur_cent] = num_list[cur_cent], num_list[start]
    quick_sort(num_list, start, cur_cent)
    quick_sort(num_list, cur_cent+1, end)

def quick_sort2(num_list, start, end):
    if end - start <= 1:
        return
    if end - start == 2:
        if num_list[end-1] < num_list[start]:
            num_list[end-1], num_list[start] = num_list[start], num_list[end-1]
        return
    piv = num_list[end-1]
    cur_ind = start
    cur_cent = start
    while cur_ind < end:
        if piv >= num_list[cur_ind]:
            num_list[cur_ind], num_list[cur_cent] = num_list[cur_cent], num_list[cur_ind]
            cur_cent += 1
        cur_ind += 1
    quick_sort2(num_list, start, cur_cent-1)
    quick_sort2(num_list, cur_cent, end)

def target_sort(num_list):
    quick_sort2(num_list, 0, len(num_list))
    print num_list
    return num_list

def main():
    rands1 = range(NUM)
    random.shuffle(rands1)
    rands2 = copy.deepcopy(rands1)
    a = sorted(rands1)
    assert a != rands2
    b = target_sort(rands2)
    assert a == b
    print 'success'
    return

if __name__ == '__main__':
    main()
