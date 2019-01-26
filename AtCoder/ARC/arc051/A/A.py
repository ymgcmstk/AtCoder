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

def check_in_blue(bx1, by1, bx2, by2, rx, ry):
    if bx1 <= rx and rx <= bx2:
        if by1 <= ry and ry <= by2:
            return False
    return True

def check_in_red(rx, ry, rr, bx, by):
    if (rx-bx)*(rx-bx) + (ry-by)*(ry-by) <= rr*rr:
        return False
    return True

rx, ry, rr = get_line(int)
bx1, by1, bx2, by2 = get_line(int)


red_flg = False
for _x, _y in zip([0, 1, 0, -1], [1, 0, -1, 0]):
    red_flg = red_flg | check_in_blue(bx1, by1, bx2, by2, rx + _x * rr, ry + _y * rr)
if red_flg:
    print 'YES'
else:
    print 'NO'

bx = float(bx1+bx2)/2
by = float(by1+by2)/2

bx_ = bx2 - bx
by_ = by2 - by

blue_flg = False
for _x, _y in zip([1, 1, -1, -1], [1, -1, -1, 1]):
    blue_flg = blue_flg | check_in_red(rx, ry, rr, bx+bx_*_x, by+by_*_y)
if blue_flg:
    print 'YES'
else:
    print 'NO'
