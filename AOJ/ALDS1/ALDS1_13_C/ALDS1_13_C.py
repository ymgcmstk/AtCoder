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
    lcs_list = [0] * (len(str1) + 1)
    for i in range(len(str2)):
        for j in range(len(str1)-1, -1, -1):
            if str2[i] == str1[j]:
                lcs_list[j+1] = max(lcs_list[j] + 1, lcs_list[j+1])
    return lcs_list[-1]

def main():
    N = int(get_line())
    for i in range(N):
        str1 = get_line()
        str2 = get_line()
        print get_LCS(str1, str2)

if __name__ == '__main__':
    main()
