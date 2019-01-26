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

def ESearch(TorF, A, cur_ind, cur_sum):
    if cur_sum > 2000:
        return
    TorF[cur_sum] = True
    if cur_ind == len(A):
        return
    ESearch(TorF, A, cur_ind+1, cur_sum)
    ESearch(TorF, A, cur_ind+1, cur_sum+A[cur_ind])

def DP(TorF, A):
    for i in A:
        for j in range(2000-i, -1, -1):
            if TorF[j]:
                TorF[j + i] = True

def main():
    N = int(get_line())
    A = get_line(integer=True)
    Q = int(get_line())
    M = get_line(integer=True)

    TorF = [False] * 2001
    TorF[0] = True

    # ESearch(TorF, A, 0, 0)
    DP(TorF, A)

    for i in M:
        if TorF[i]:
            print 'yes'
        else:
            print 'no'

if __name__ == '__main__':
    main()
