#!/usr/bin/env python
# -*- coding:utf-8 -*-
import sys
import heapq

class Graph(object):
    def __init__(self, node):
        self._node = node
        self._edges = range(self._node)
        for i in self._edges:
            self._edges[i] = []
    def input_edge(self, i_from, i_to, cost):
        self._edges[i_from].append([cost, i_to])
    def prim(self):
        ans = 0
        tree_inds = set([0])
        hq = []
        for cost, i_to in self._edges[0]:
            heapq.heappush(hq, [cost, i_to])
        while len(tree_inds) < self._node and len(hq) > 0:
            cost, i_to = heapq.heappop(hq)
            if i_to in tree_inds:
                continue
            tree_inds.add(i_to)
            ans += cost
            for chl_cost, chl_i_to in self._edges[i_to]:
                if chl_i_to in tree_inds:
                    continue
                heapq.heappush(hq, [chl_cost, chl_i_to])
        return ans

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
