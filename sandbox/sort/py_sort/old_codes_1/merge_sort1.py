#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *
set_debugger(send_email=False, error_func=None)
import random
import copy
NUM = 100

def merge_sort(num_list):
    if len(num_list) == 2:
        if num_list[0] > num_list[1]:
            temp = num_list[0]
            num_list[0] = num_list[1]
            num_list[1] = temp
    if len(num_list) < 3:
        return num_list
    first  = merge_sort(num_list[:len(num_list)/2])
    second = merge_sort(num_list[len(num_list)/2:])
    first_ind = 0
    second_ind = 0
    ans_list = []
    while first_ind < len(first) and second_ind < len(second):
        if first[first_ind] < second[second_ind]:
            ans_list.append(first[first_ind])
            first_ind += 1
        else:
            ans_list.append(second[second_ind])
            second_ind += 1
    while first_ind < len(first):
        ans_list.append(first[first_ind])
        first_ind += 1
    while second_ind < len(second):
        ans_list.append(second[second_ind])
        second_ind += 1
    return ans_list

def main():
    rands1 = range(NUM)
    random.shuffle(rands1)
    rands2 = copy.deepcopy(rands1)
    a = sorted(rands1)
    assert a != rands2
    b = merge_sort(rands2)
    assert a == b
    print 'success'
    return

if __name__ == '__main__':
    main()
