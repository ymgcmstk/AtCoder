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
        if directed:
            self.Edges[i_to].append([i_from, cost])
    def dijkstra(self, i_from):
        distance = [float('inf') for i in range(self.N)]
        distance[i_from] = 0
        queue = []
        for i in self.Edges[i_from]:
            heapq.heappush(queue, (i[1], i[0]))
        while len(queue) > 0:
            cost, i_to = heapq.heappop(queue)
            if distance[i_to] <= cost:
                continue
            distance[i_to] = cost
            for i in self.Edges[i_to]:
                if distance[i[0]] != float('inf'):
                    continue
                heapq.heappush(queue, (i[1] + distance[i_to], i[0]))
        return distance

def input_data(directed=False):
    N = int(sys.stdin.readline())
    graph = Graph(N)
    for _ in range(N):
        loaded = [int(num) for num in sys.stdin.readline().split(' ')]
        if not directed:
            assert len(graph.Edges[loaded[0]]) == 0
        for i in range((len(loaded) - 2)/2):
            graph.input_edge(loaded[0], loaded[2*i+2], loaded[2*i+3], directed)
        if not directed:
            assert loaded[1] == len(graph.Edges[loaded[0]])
    return graph

def main():
    graph = input_data(False)
    for i, j in enumerate(graph.dijkstra(0)):
        print i, j
    return

if __name__ == '__main__':
    main()
