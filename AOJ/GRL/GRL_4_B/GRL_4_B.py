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

def top_sort(nodes, par_num):
    ans_nodes = []
    nodes_queue = []
    for node in range(len(par_num)):
        if par_num[node] == 0:
            nodes_queue.append(node)
    while len(ans_nodes) < len(nodes):
        assert len(nodes_queue) > 0
        cur_node = nodes_queue[0]
        nodes_queue = nodes_queue[1:]
        ans_nodes.append(cur_node)
        for i in nodes[cur_node]:
            par_num[i] -= 1
            if par_num[i] == 0:
                nodes_queue.append(i)
    return ans_nodes

def main():
    N, E = get_line(True)
    nodes = []
    par_num = [0] * N
    for i in range(N):
        nodes.append([])
    for i in range(E):
        s, t = get_line(True)
        par_num[t] += 1
        nodes[s].append(t)
    ans_nodes = top_sort(nodes, par_num)
    for i in ans_nodes:
        print i

if __name__ == '__main__':
    main()
