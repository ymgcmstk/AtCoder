#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *
set_debugger(send_email=False, error_func=None)
import random
import copy
NUM = 100

def max_heapify(num_list, head, end=None):
    if end is None:
        end = len(num_list)
    if head * 2 + 1 >= end:
        return
    max_num = head * 2 + 1
    if head * 2 + 2 < end:
        if num_list[head * 2 + 2] > num_list[head * 2 + 1]:
            max_num += 1
    # swap
    if num_list[head] < num_list[max_num]:
        num_list[head], num_list[max_num] = num_list[max_num], num_list[head]
    max_heapify(num_list, max_num, end)

def check_max_heap(num_list, head, end=None):
    if end is None:
        end = len(num_list)
    for i in range(head, end):
        if i * 2 + 1 > end - 1:
            return True
        if num_list[i * 2 + 1] > num_list[i]:
            print num_list
            print 'i * 2 + 1'
            raise Exception()
        if i * 2 + 2 > end - 1:
            return True
        if num_list[i * 2 + 2] > num_list[i]:
            print num_list
            print 'i * 2 + 2'
            raise Exception()

def target_sort(num_list):
    # max-heapify
    for i in range(len(num_list))[::-1]:
        max_heapify(num_list, i)
    check_max_heap(num_list, i)
    # sort
    for i in range(len(num_list))[::-1]:
        if i != num_list[0]:
            print i
            print num_list
            exit()
        num_list[i], num_list[0] = num_list[0], num_list[i]
        max_heapify(num_list, 0, i)
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
    """
    test_list = [
        [0, 1, 2],
        [0, 2, 1],
        [1, 0, 2],
        [1, 2, 0],
        [2, 0, 1],
        [2, 1, 0],
    ]
    for i in range(len(test_list)):
        max_heapify(test_list[i], 0)
        print test_list[i]
        assert test_list[i][0] == 2
    """
