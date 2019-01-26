#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *
import sys
import heapq

class Graph:
    N = None
    Edges = []
    def __init__(self, N=None):
        self.N = N
        for i in range(N):
            self.Edges.append([])
    def input_edge(self, i_from, i_to, cost, directed=False):
        self.Edges[i_from].append([i_to, cost])
        if not directed:
            self.Edges[i_to].append([i_from, cost])
    def dijkstra(self, start):
        dist = range(self.N)
        for i in range(self.N):
            dist[i] = float("inf")
        dist[start] = 0
        hq = []
        for i in self.Edges[start]:
            heapq.heappush(hq, (i[1], i[0]))
        while len(hq) > 0:
            cur_item = heapq.heappop(hq)
            if dist[cur_item[1]] < float("inf"):
                continue
            dist[cur_item[1]] = cur_item[0]
            for i in self.Edges[cur_item[1]]:
                if dist[i[0]] < float("inf"):
                    continue
                heapq.heappush(hq, (i[1] + cur_item[0], i[0]))
        return dist

def input_data(directed=False):
    N = int(sys.stdin.readline())
    graph = Graph(N)
    for _ in range(N):
        loaded = [int(num) for num in sys.stdin.readline().split(' ')]
        if directed:
            assert len(graph.Edges[loaded[0]]) == 0
        for i in range((len(loaded) - 2)/2):
            graph.input_edge(loaded[0], loaded[2*i+2], loaded[2*i+3], directed)
        if directed:
            assert loaded[1] == len(graph.Edges[loaded[0]])
    return graph

def main():
    graph = input_data(True)
    for i, j in enumerate(graph.dijkstra(0)):
        print i, j
    return

if __name__ == '__main__':
    main()
