# -*- coding:utf-8 -*-
import sys

def split_int(string):
    return [int(x) for x in string.split()]

def get_line(integer=False):
    string = sys.stdin.readline().rstrip()
    if integer:
        return split_int(string)
    else:
        return string

char = get_line()[0]

if char in ['O', 'P', 'K', 'L']:
    print 'Right'
else:
    print 'Left'
