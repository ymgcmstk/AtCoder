#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *
import sys
import heapq

class Graph(object):
    def __init__(self, adj_list):
        self._adj_list = adj_list
        for i in self._adj_list:
            assert isinstance(i, dict)
            for j in i.keys():
                assert isinstance(j, int)
                assert j < len(self._adj_list)
    def dijkstra(self, start=0, end=None):
        distance = [float('inf')] * len(self._adj_list)
        pr_queue = [(0, start)]
        fin_set = set()
        while len(fin_set) < len(self._adj_list) and len(pr_queue) > 0:
            targ_dist, targ = heapq.heappop(pr_queue)
            if targ in fin_set:
                continue
            fin_set.add(targ)
            if end == targ:
                return targ_dist
            distance[targ] = targ_dist
            for i in self._adj_list[targ]:
                if i in fin_set:
                    continue
                heapq.heappush(pr_queue, (targ_dist+self._adj_list[targ][i], i))
        return distance
    def bellman_ford(self, start=0, end=None):
        distance = [float('inf')] * len(self._adj_list)
        distance[start] = 0

        fin_flg = False
        while not fin_flg:
            fin_flg = True
            for n_from, n_tos in enumerate(self._adj_list):
                for n_to in n_tos:
                    if distance[n_to] > distance[n_from] + n_tos[n_to]:
                        distance[n_to] = distance[n_from] + n_tos[n_to]
                        fin_flg = False
        if not end is None:
            return distance[end]
        return distance

def split_int(string):
    return [int(x) for x in string.split()]

def get_line(integer=False):
    string = sys.stdin.readline().rstrip()
    if integer:
        return split_int(string)
    else:
        return string

def main():
    N = int(get_line())
    adj_list = [0] * N
    for i in range(N):
        cur_line = get_line(integer=True)
        targ_ind = cur_line[0]
        targ_num = cur_line[1]
        adj_list[targ_ind] = {cur_line[2+i*2]: cur_line[3+i*2] for i in range(targ_num)}
    G = Graph(adj_list)
    # dist = G.dijkstra()
    dist = G.bellman_ford()
    for num, i in enumerate(dist):
        print num, i

if __name__ == '__main__':
    main()
