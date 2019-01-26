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

def initialize_seg_tree(As):
    n = 1
    while len(As) > 2 ** n:
        n += 1 # bit演算でも可
    seg_tree = [float('inf')] * (2 ** (n + 1) - 1)
    for As_i in range(len(As)):
        update_seg_tree(As, seg_tree, As_i, As[As_i], n)
    return seg_tree, n

def update_seg_tree(As, seg_tree, x, y, n):
    cur_ind = (2 ** n - 1) + x
    if seg_tree[cur_ind] == y:
        return
    if seg_tree[cur_ind] > y:
        while seg_tree[cur_ind] > y and cur_ind >= 0:
            seg_tree[cur_ind] = y
            cur_ind = (cur_ind - 1) / 2
        return
    initial_value = seg_tree[cur_ind]
    seg_tree[cur_ind] = y
    cur_ind = (cur_ind - 1) / 2
    while seg_tree[cur_ind] == initial_value and seg_tree[cur_ind*2+1] <= initial_value and seg_tree[cur_ind*2+1] <= initial_value and cur_ind >= 0:
        seg_tree[cur_ind] = y
        cur_ind = (cur_ind - 1) / 2
    return

def find_seg_tree(As, seg_tree, x, y, n, cur_ind, cur_n):
    cur_start = (cur_ind - 2 ** (cur_n) + 1) * (2 ** (n - cur_n))
    cur_end = cur_start + (2 ** (n - cur_n)) - 1
    if cur_start >= x and cur_end <= y:
        return seg_tree[cur_ind]
    if cur_start > y or cur_end < x:
        return float('inf')
    cur_min = find_seg_tree(As, seg_tree, x, y, n, cur_ind * 2 + 1, cur_n + 1)
    cur_min = min(cur_min, find_seg_tree(As, seg_tree, x, y, n, cur_ind * 2 + 2, cur_n + 1))
    return cur_min

def main():
    N, Q = get_line(True)
    As = [2**31-1] * N
    seg_tree, n = initialize_seg_tree(As)
    for _ in range(Q):
        com, x, y = get_line(True)
        if com == 0:
            update_seg_tree(As, seg_tree, x, y, n) # As[x] -> y
        elif com == 1:
            print find_seg_tree(As, seg_tree, x, y, n, 0, 0) # x ~ y
        else:
            raise Exception()

if __name__ == '__main__':
    main()
