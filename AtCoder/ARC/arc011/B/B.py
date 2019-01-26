# -*- coding:utf-8 -*-
import sys

def split_with_func(string, func):
    return [func(x) for x in string.split()]

def get_line(func=None):
    string = sys.stdin.readline().rstrip()
    if func is not None:
        return split_with_func(string, func)
    else:
        return string

replacer = {
    'b': 1,
    'c': 1,
    'd': 2,
    'w': 2,
    't': 3,
    'j': 3,
    'f': 4,
    'q': 4,
    'l': 5,
    'v': 5,
    's': 6,
    'x': 6,
    'p': 7,
    'm': 7,
    'h': 8,
    'k': 8,
    'n': 9,
    'g': 9,
    'z': 0,
    'r': 0,
}
N = get_line(int)[0]
Ws = get_line(str)
ans_str = ''
for W in Ws:
    cur_w = W.lower()
    cur_str = ''
    for cur_c in cur_w:
        if cur_c in replacer.keys():
            cur_str += str(replacer[cur_c])
    ans_str = ans_str.strip() + ' ' + cur_str

print ans_str.strip()
