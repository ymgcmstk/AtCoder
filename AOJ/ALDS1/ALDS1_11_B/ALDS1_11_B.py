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

def dfs(dot2dot, dot2first, dot2fin, cur_dot, cur_turn):
    dot2first[cur_dot] = cur_turn
    for i in dot2dot[cur_dot]:
        if dot2first[i] >= 0:
            continue
        cur_turn += 1
        # print 'DEBUG:', cur_turn, cur_dot, i
        cur_turn = dfs(dot2dot, dot2first, dot2fin, i, cur_turn)
    cur_turn += 1
    dot2fin[cur_dot] = cur_turn
    return cur_turn

def main():
    N = int(get_line())
    dot2dot   = {i:[] for i in range(1, N+1)}
    dot2first = {i:-1 for i in range(1, N+1)}
    dot2fin   = {i:-1 for i in range(1, N+1)}
    for i in range(N):
        cur_line = get_line(True)
        for j in cur_line[2:]:
            dot2dot[cur_line[0]].append(j)
            # dot2dot[j].append(cur_line[0])
    dfs(dot2dot, dot2first, dot2fin, 1, 1)
    for i in sorted(dot2dot.keys()):
        print i, dot2first[i], dot2fin[i]

if __name__ == '__main__':
    main()
