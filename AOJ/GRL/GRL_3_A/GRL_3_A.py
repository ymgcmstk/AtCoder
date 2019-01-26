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

class Node(object):
    def __init__(self, ind):
        self.ind = ind
        self.edges = []
    def add_edge(self, edge):
        self.edges.append(edge)

def dfs(prenum, minnum, nodes, next_node, cur_num):
    prenum[next_node] = cur_num
    minnum[next_node] = cur_num
    cur_min = cur_num
    for edge in nodes[next_node].edges:
        if prenum[edge] == float('inf'):
            cur_min = min(cur_min, dfs(prenum, minnum, nodes, edge, cur_num+1))
        else:
            cur_min = min(cur_min, minnum[edge])
    minnum[next_node] = cur_min
    return cur_min

def main():
    V, E = get_line(True)
    nodes = [Node(i) for i in range(V)]
    for _ in range(E):
        s, t = get_line(True)
        nodes[s].add_edge(t)
        nodes[t].add_edge(s)
    prenum = [float('inf') for _ in range(V)]
    minnum = [float('inf') for _ in range(V)]
    start_point = 0
    dfs(prenum, minnum, nodes, start_point, 0)
    if len(nodes[start_point].edges) > 1:
        for edge in nodes[start_point].edges:
            if minnum[edge] > 0:
                print start_point
    pre2node = {i: num for num, i in enumerate(prenum)}
    for i in range(2, V):
        par = pre2node[i-1]
        chl = pre2node[i]
        if minnum[chl] >= prenum[par]:
            print par

if __name__ == '__main__':
    main()
