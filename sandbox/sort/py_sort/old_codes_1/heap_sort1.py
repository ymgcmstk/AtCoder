#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *
set_debugger(send_email=False, error_func=None)
import random
import copy
NUM = 100

def max_heapify(num, num_list):
    if 2 * num + 1 >= len(num_list):
        return num_list
    change_target = 2 * num + 1
    if 2 * num + 2 < len(num_list):
        if num_list[2 * num + 2] > num_list[2 * num + 1]:
            change_target += 1
    if num_list[num] < num_list[change_target]:
        temp = num_list[num]
        num_list[num] = num_list[change_target]
        num_list[change_target] = temp
        return max_heapify(change_target, num_list)
    return num_list

def heap_sort(num_list):
    for i in xrange(len(num_list)-1, -1, -1):
        num_list = max_heapify(i, num_list)
    for i in xrange(len(num_list)):
        temp = num_list[-1-i]
        num_list[-1-i] = num_list[0]
        num_list[0] = temp
        num_list[:-1-i] = max_heapify(0, num_list[:-1-i])
    return num_list

def main():
    rands1 = range(NUM)
    random.shuffle(rands1)
    rands2 = copy.deepcopy(rands1)
    a = sorted(rands1)
    assert a != rands2
    b = heap_sort(rands2)
    assert a == b
    print 'success'
    return

if __name__ == '__main__':
    main()
