# -*- coding:utf-8 -*-
import sys
import heapq

def split_int(string):
    return [int(x) for x in string.split()]

def get_line(integer=False):
    string = sys.stdin.readline().rstrip()
    if integer:
        return split_int(string)
    else:
        return string

def main():
    cur_line = get_line().split()
    cur_heap = []
    while cur_line[0] != 'end':
        if cur_line[0] == 'insert':
            heapq.heappush(cur_heap, -1 * int(cur_line[1]))
        elif cur_line[0] == 'extract':
            print -1 * heapq.heappop(cur_heap)

        cur_line = get_line().split()


if __name__ == '__main__':
    main()
