# -*- coding:utf-8 -*-
import sys

def split_with_func(string, func):
    return [func(x) for x in string.split()]

def get_line(func=None):
    string = sys.stdin.readline().rstrip()
    if func is not None:
        return split_with_func(string, func)
    else:
        return string

N = get_line(int)[0]
Ws = [get_line(str)[0] for i in range(N)]
a = set()
b = set([Ws[0]])
win = True
for i in range(len(Ws)-1):
    if not Ws[i][-1] == Ws[i+1][0]:
        if win:
            print 'WIN'
        else:
            print 'LOSE'
        exit()
    if win:
        if Ws[i+1] in a:
            print 'WIN'
            exit()
        a.add(Ws[i+1])
    else:
        if Ws[i+1] in b:
            print 'LOSE'
            exit()
        b.add(Ws[i+1])
    win = not win
print 'DRAW'
