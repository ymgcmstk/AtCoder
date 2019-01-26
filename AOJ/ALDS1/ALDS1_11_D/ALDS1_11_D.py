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

def dfs(dot_flg, linked_list, flg, cur_dot):
    dot_flg[cur_dot] = flg
    for i in linked_list[cur_dot]:
        if dot_flg[i] == -1:
            dfs(dot_flg, linked_list, flg, i)
        else:
            assert dot_flg[i] == flg

def main():
    N, M = get_line(True)
    linked_list = []
    dot_flg = [-1] * N
    for i in range(N):
        linked_list.append([])
    for i in range(M):
        left, right = get_line(True)
        linked_list[left].append(right)
        linked_list[right].append(left)
    for i in range(N):
        if dot_flg[i] == -1:
            dfs(dot_flg, linked_list, i, i)

    Q = int(get_line())
    for i in range(Q):
        left, right = get_line(True)
        if dot_flg[left] == dot_flg[right]:
            print 'yes'
        else:
            print 'no'

if __name__ == '__main__':
    main()
