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
    def dijkstra(self, i_start):
        dist = range(self._N)
        for i in range(self._N):
            dist[i] = float('inf')
        dist[i_start] = 0
        hq = []
        for cost, i_to in self._edges[i_start]:
            heapq.heappush(hq, [cost, i_to])
        while len(hq) > 0:
            cost, i_to = heapq.heappop(hq)
            if dist[i_to] < float('inf'):
                continue
            dist[i_to] = cost
            for chl_cost, chl_i_to in self._edges[i_to]:
                if dist[chl_i_to] < float('inf'):
                    continue
                heapq.heappush(hq, [chl_cost + dist[i_to], chl_i_to])
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
    res = G.dijkstra(0)
    for i, num in enumerate(res):
        print i, num

if __name__ == '__main__':
    main()
