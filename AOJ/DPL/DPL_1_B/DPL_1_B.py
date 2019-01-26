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

class Baggage(object):
    def __init__(self, value, weight):
        self.value  = value
        self.weight = weight

def main():
    N, W = get_line(True)
    bags = []
    for i in range(N):
        val, weight = get_line(True)
        bags.append(Baggage(val, weight))
    costs = [0] * (W + 1)
    for i in range(N):
        for j in range(W, bags[i].weight-1, -1):
            costs[j] = max(costs[j], costs[j-bags[i].weight] + bags[i].value)
    print costs[W]

if __name__ == '__main__':
    main()
