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

N = int(get_line())

S2L = {}
small_set = set()

for i in range(N):
    l, m, s = get_line().split()
    S2L[l] = (int(m), s)
    small_set.add(s)

first_ind = None
for i in S2L.keys():
    if not i in small_set:
        first_ind = i
        break

cur_m = 1
cur_ind = first_ind
while cur_ind in S2L.keys():
    m, s = S2L[cur_ind]
    cur_m *= m
    cur_ind = s

print '1%s=%d%s' % (first_ind, cur_m, cur_ind)
