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

def main():
    H, W = get_line(True)
    binmap  = []
    linemap = []
    for i in range(H):
        binmap.append(get_line(True))
        cur_line = []
        if i == 0:
            for j in binmap[-1]:
                cur_line.append(1 - j)
        else:
            for old_j, j in zip(linemap[-1], binmap[-1]):
                if j == 1:
                    cur_line.append(0)
                else:
                    cur_line.append(old_j + 1)
        linemap.append(cur_line)
    cur_max = 0
    for i in range(H):
        cur_stack = [(0, -1)]
        for ind, j in enumerate(linemap[i]):
            while j < cur_stack[-1][0]:
                old_j, old_ind = cur_stack[-1]
                cur_stack = cur_stack[:-1]
                cur_max = max(cur_max, (ind - old_ind) * old_j)
            cur_stack.append((j, ind))
        while len(cur_stack) > 0:
            old_j, old_ind = cur_stack[-1]
            cur_stack = cur_stack[:-1]
            cur_max = max(cur_max, (ind - old_ind) * old_j)
    print cur_max

if __name__ == '__main__':
    main()
