#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *
set_debugger(send_email=False, error_func=None)
import random
import copy
NUM = 100

def quick_sort(num_list):
    if len(num_list) < 2:
        return num_list
    cur_head = 1
    for i in range(1, len(num_list)):
        if num_list[0] > num_list[i]:
            num_list.insert(cur_head, num_list[i])
            del num_list[i+1]
            cur_head += 1
    num_list.insert(cur_head, num_list[0])
    del num_list[0]

    num_list[:cur_head-1] = quick_sort(num_list[:cur_head-1])
    num_list[cur_head:] = quick_sort(num_list[cur_head:])
    return num_list

def main():
    rands1 = range(NUM)
    random.shuffle(rands1)
    rands2 = copy.deepcopy(rands1)
    a = sorted(rands1)
    assert a != rands2
    b = quick_sort(rands2)
    assert a == b
    print 'success'
    return

if __name__ == '__main__':
    main()
