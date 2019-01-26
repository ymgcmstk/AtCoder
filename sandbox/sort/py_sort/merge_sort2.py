#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *
set_debugger(send_email=False, error_func=None)
import random
import copy
NUM = 100

def merge_sort(targ_list, start, end):
    if end - start == 2:
        if targ_list[end-1] < targ_list[start]:
            targ_list[end-1], targ_list[start] = targ_list[start], targ_list[end-1]
        return
    if end - start < 2:
        return
    mid = (start + end) / 2
    merge_sort(targ_list, start, mid)
    merge_sort(targ_list, mid, end)
    temp_list = [0] * (end - start)
    left_ind = start
    right_ind = mid
    cur_ind = 0
    while left_ind < mid and right_ind < end:
        if targ_list[left_ind] < targ_list[right_ind]:
            temp_list[cur_ind] = targ_list[left_ind]
            left_ind += 1
        else:
            temp_list[cur_ind] = targ_list[right_ind]
            right_ind += 1
        cur_ind += 1
    while left_ind < mid:
        temp_list[cur_ind] = targ_list[left_ind]
        cur_ind += 1
        left_ind += 1
    while right_ind < end:
        temp_list[cur_ind] = targ_list[right_ind]
        cur_ind += 1
        right_ind += 1
    targ_list[start:end] = temp_list

def target_sort(num_list):
    merge_sort(num_list, 0, len(num_list))
    return  num_list

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
