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

def bfs(dot2dot, dot2dist, start_dot, start_turn):
    # もうちょっと賢くかけそう, queue = [start_dot]として、queueに突っ込む段階でdistを入力
    queue = [(start_dot, start_turn)]
    while len(queue) > 0:
        cur_dot, cur_turn = queue[0]
        queue = queue[1:]
        if dot2dist[cur_dot] >= 0:
            continue
        dot2dist[cur_dot] = cur_turn
        for i in dot2dot[cur_dot]:
            if dot2dist[i] >= 0:
                continue
            queue.append((i, cur_turn+1))

def main():
    N = int(get_line())
    dot2dot  = {i: [] for i in range(1, N+1)}
    dot2dist = {i: -1 for i in range(1, N+1)}
    for i in range(N):
        cur_line = get_line(True)
        for j in cur_line[2:]:
            dot2dot[cur_line[0]].append(j)
    bfs(dot2dot, dot2dist, 1, 0)
    for i in sorted(dot2dist.keys()):
        print i, dot2dist[i]

if __name__ == '__main__':
    main()
