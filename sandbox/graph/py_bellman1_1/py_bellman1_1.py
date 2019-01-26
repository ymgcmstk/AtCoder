#!/usr/bin/env python
# -*- coding:utf-8 -*-
import sys
import heapq

class Graph:
    def __init__(self, N):
        self._N = N
        self._edges = []
        for i in range(N):
            self._edges.append([])
    def input_edge(self, i_from, i_to, cost, directed=False):
        self._edges[i_from].append([cost, i_to])
        if directed:
            self._edges[i_to].append([cost, i_from])
    def bellman_ford(self, i_start):
        dist = range(self._N)
        for i in range(self._N):
            dist[i] = float('inf')
        dist[i_start] = 0
        while_flg = True
        while while_flg:
            while_flg = False
            for i_from in range(self._N):
                for cost, i_to in self._edges[i_from]:
                    if dist[i_from] == float('inf'):
                        continue
                    if dist[i_to] > dist[i_from] + cost:
                        dist[i_to] = dist[i_from] + cost
                        while_flg = True
        return dist

def get_line(integer=False):
    string = sys.stdin.readline().rstrip()
    if integer:
        return [int(x) for x in string.split()]
    else:
        return string

def input_line(directed=True):
    N = int(get_line())
    G = Graph(N)
    for _ in range(N):
        ints = get_line(integer=True)
        for i in range(ints[1]):
            G.input_edge(ints[0], ints[i*2], ints[i*2+1], directed)
    return G

def main():
    G = input_line(directed=True)
    res = G.bellman_ford(0)
    for i, num in enumerate(res):
        print i, num

if __name__ == '__main__':
    main()
