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

def calc_prod_num(mat1, mat2):
    assert mat1[1] == mat2[0]
    return mat1[0] * mat2[1] * mat1[1]

def MCM(mat_info):
    mcm_list = []
    for i in range(len(mat_info)):
        mcm_list.append([float('inf')] * len(mat_info))
        mcm_list[i][i] = 0
    cur_range = 1
    while cur_range != len(mat_info):
        for i in range(len(mat_info)-cur_range):
            for j in range(0, cur_range):
                mcm_list[i][i+cur_range] = min(mcm_list[i][i+cur_range],
                                               mcm_list[i][i+j] + mcm_list[i+j+1][i+cur_range] + mat_info[i][0] * mat_info[i+cur_range][1] * mat_info[i+j][1])
        cur_range += 1
    return mcm_list[0][-1]

def main():
    N = int(get_line())
    mat_info = [None] * N
    for i in range(N):
        x1, x2 = get_line(True)
        mat_info[i] = [x1, x2]
    print MCM(mat_info)

if __name__ == '__main__':
    main()
