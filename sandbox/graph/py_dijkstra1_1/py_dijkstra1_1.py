#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *
import sys

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
        distance = [float('inf')] * self.N
        distance[i_from] = 0
        PQ = []
        PQ.extend(self.Edges[i_from])
        PQ = sorted(PQ, key=lambda x: x[1])
        node_set = set([i_from])
        while True:
            nearest_point = PQ[0]
            del PQ[0]
            if distance[nearest_point[0]] != float('inf'):
                continue
            distance[nearest_point[0]] = nearest_point[1]
            node_set.add(nearest_point[0])
            if len(node_set) == self.N:
                break
            for i in self.Edges[nearest_point[0]]:
                if not i[0] in node_set:
                    PQ = self.add_element(PQ, [i[0], i[1] + distance[nearest_point[0]]])
        return distance
    def add_element(self, targ_list, targ_el):
        left = 0
        right = len(targ_list) - 1
        mid = (left + right) / 2
        if len(targ_list) == 0:
            return [targ_el]
        if targ_list[-1][1] <= targ_el[1]:
            targ_list.append(targ_el)
            return targ_list
        if targ_list[0][1] >= targ_el[1]:
            targ_list.insert(0, targ_el)
            return targ_list
        while True:
            if targ_list[mid][1] > targ_el[1]:
                right = mid
            elif targ_list[mid+1][1] < targ_el[1]:
                left = mid + 1
            else:
                break
            mid = (left + right) / 2
        targ_list.insert(mid+1, targ_el)
        return targ_list

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
    graph = input_data(True)
    for i, j in enumerate(graph.dijkstra(0)):
        print i, j
    return

if __name__ == '__main__':
    main()
