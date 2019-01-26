#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *
from math import log

def main():
    lines = textread('input.txt')
    num_lines = []
    for cur_line in lines:
        num_lines.append([int(i) for i in cur_line.split()])
    num_lines_up = []
    for i in range(len(num_lines[0])):
        cur_line = []
        for line in num_lines:
            cur_line.append(line[i])
        num_lines_up.append(cur_line)
    num_lines_diag = []
    for i in range(len(num_lines[0])):
        cur_line = []
        for line in num_lines:
            cur_line.append(line[i])
        num_lines_up.append(cur_line)
    return num_lines.extend(num_lines_up)

def get_max_from_line(line, ADJ):
    cur_sum = 1
    last_zero = -1
    cur_max = 0
    cur_ind = -1
    for i in range(len(line)):
        if line[i] == 0:
            last_zero = i
            cur_sum = 1
            continue
        cur_sum *= line[i]
        if i - last_zero >= ADJ + 1:
            cur_sum /= line[i - ADJ]
        if cur_sum > cur_max and i - last_zero >= ADJ:
            cur_ind = i
            cur_max = cur_sum
    return cur_max

def get_max_from_lines(lines, ADJ):
    cur_max = 0
    for line in lines:
        cur_max = max(cur_max, get_max_from_line(line, ADJ))
    return cur_max


if __name__ == '__main__':

    get_max_from_lines(lines, 4)
