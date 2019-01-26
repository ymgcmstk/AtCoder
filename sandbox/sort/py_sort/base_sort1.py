#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *
set_debugger(send_email=False, error_func=None)
import random
import copy
NUM = 100

def target_sort(num_list):
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
