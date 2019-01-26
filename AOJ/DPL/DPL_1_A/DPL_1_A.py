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

def main():
    M, _  = get_line(True)
    coins = get_line(True)
    coin_num = [float('inf')] * (M + 1)
    coin_num[0] = 0
    for i in coins:
        for j in range(i, M + 1):
            coin_num[j] = min(coin_num[j-i]+1, coin_num[j])
    print coin_num[M]

if __name__ == '__main__':
    main()
