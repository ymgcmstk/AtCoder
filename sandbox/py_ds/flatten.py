#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *
import copy

def flatten(targ_list):
    new_list = copy.deepcopy(targ_list)
    for i in reversed(range(len(new_list))):
        if isinstance(new_list[i], list):
            new_list[i:i+1] = flatten(new_list[i])
    return new_list

def main():
    a = [1, 2, [3, 4, [5], 4, [5, 6], 2], 4]
    print a
    print flatten(a)
    print a
    return

if __name__ == '__main__':
    main()
