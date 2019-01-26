# -*- coding:utf-8 -*-
import sys
import datetime as dt

def split_int(string):
    return [int(x) for x in string.split()]

def get_line(integer=False):
    string = sys.stdin.readline().rstrip()
    if integer:
        return split_int(string)
    else:
        return string

def check_condition(curD):
    if curD.year % (curD.month * curD.day) == 0:
        return True
    return False

def print_curD(curD):
    ans = ''
    ans += str(curD.year)
    cur_ans = str(curD.month)
    if len(cur_ans) == 1:
        cur_ans = '0' + cur_ans
    ans += '/' + cur_ans
    cur_ans = str(curD.day)
    if len(cur_ans) == 1:
        cur_ans = '0' + cur_ans
    ans += '/' + cur_ans
    print ans

N = get_line()

Y, M, D = [int(i) for i in N.split('/')]

curD = dt.date(Y, M, D)



while not check_condition(curD):
    curD += dt.timedelta(days=1)

print_curD(curD)
