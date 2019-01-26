#!/usr/bin/env python
# -*- coding:utf-8 -*-
import sys
import heapq

class Graph(object):
    def __init__(self, num):
        self._num = num
        self._adj_list = [{} for _ in range(num)]
    def input_edge(self, n_from, n_to, cost):
        self._adj_list[n_from][n_to] = cost
    def prim(self):
        start = 0
        weight = 0
        pr_queue = []
        heapq.heappush(pr_queue, (0, start))
        fin_set = set()
        while len(fin_set) < self._num and len(pr_queue) > 0:
            targ_dist, targ = heapq.heappop(pr_queue)
            if targ in fin_set:
                continue
            fin_set.add(targ)
            weight += targ_dist
            for next_targ in self._adj_list[targ]:
                if next_targ in fin_set:
                    continue
                heapq.heappush(pr_queue, (self._adj_list[targ][next_targ], next_targ))
        if len(fin_set) < self._num:
            raise Exception()
        return weight

def get_line(integer=False):
    string = sys.stdin.readline().rstrip()
    if integer:
        return [int(x) for x in string.split()]
    else:
        return string

def input_data():
    N = int(get_line())
    G = Graph(N)
    for i in range(N):
        cur_line = get_line(True)
        for j in range(N):
            if cur_line[j] < 0:
                continue
            G.input_edge(i, j, cur_line[j])
    return G

def main():
    G = input_data()
    print G.prim()
    return

if __name__ == '__main__':
    main()
