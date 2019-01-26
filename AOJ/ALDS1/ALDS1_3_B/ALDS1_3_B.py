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

class Process(object):
    def __init__(self, name, time):
        self._name = name
        self._time = time
    def execute(self, time):
        if time < self._time:
            self._time -= time
            return time
        else:
            ans = self._time
            self._time = 0
            return ans
    def finish(self):
        if self._time == 0:
            return True
        return False
    def get_name(self):
        return self._name

def main():
    N, Q = get_line(integer=True)
    cur_queue = []
    for i in range(N):
        name, time = get_line().split()
        cur_queue.append(Process(name, int(time)))
    elapsed = 0
    while len(cur_queue) > 0:
        cur_pr = cur_queue[0]
        elapsed += cur_pr.execute(Q)
        cur_queue = cur_queue[1:]
        if cur_pr.finish():
            print cur_pr.get_name(), elapsed
        else:
            cur_queue.append(cur_pr)

if __name__ == '__main__':
    main()
