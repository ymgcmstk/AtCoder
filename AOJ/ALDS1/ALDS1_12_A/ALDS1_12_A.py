# -*- coding:utf-8 -*-
import sys
import heapq

def split_int(string):
    return [int(x) for x in string.split()]

def get_line(integer=False):
    string = sys.stdin.readline().rstrip()
    if integer:
        return split_int(string)
    else:
        return string

class Edge(object):
    def __init__(self, to, cost):
        self.to = to
        self.cost = cost

def prim(edges, start=0):
    ans = 0
    cur_heap = []
    node_set = set()
    node_set.add(start)
    for i in edges[start]:
        heapq.heappush(cur_heap, (i.cost, i.to))
    while len(node_set) < len(edges) and len(cur_heap) > 0:
        cost, to = heapq.heappop(cur_heap)
        if to in node_set:
            continue
        ans += cost
        node_set.add(to)
        for i in edges[to]:
            if i.to in node_set:
                continue
            heapq.heappush(cur_heap, (i.cost, i.to))
    return ans


def main():
    N = int(get_line())
    edges = []
    for i in range(N):
        cur_edges = []
        for num, j in enumerate(get_line(True)):
            if j == -1:
                continue
            cur_edges.append(Edge(num, j))
        edges.append(cur_edges)
    print prim(edges)

if __name__ == '__main__':
    main()
