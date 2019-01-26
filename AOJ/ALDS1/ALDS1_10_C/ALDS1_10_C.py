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

def get_LCS(str1, str2):
    cur_LCS = []
    for i in range(len(str2) + 1):
        cur_LCS.append([0] * (len(str1) + 1))

    for i in range(1, len(str2) + 1):
        for j in range(1, len(str1) + 1):
            cur_LCS[i][j] = max(cur_LCS[i-1][j], cur_LCS[i][j-1])
            if str2[i-1] == str1[j-1]:
                cur_LCS[i][j] = max(cur_LCS[i][j], cur_LCS[i-1][j-1]+1)
    return cur_LCS[-1][-1]

def main():
    N = int(get_line())
    for i in range(N):
        str1 = get_line()
        str2 = get_line()
        print get_LCS(str1, str2)

if __name__ == '__main__':
    main()
