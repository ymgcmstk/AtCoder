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

W = 8

def add_Q_to_map(x, y, Qmap, vrt, hrz, diag1, diag2):
    vrt[x] = True
    hrz[y] = True
    diag1[x + y] = True
    diag2[x - y + 7] = True
    Qmap[x][y] = True

def remove_Q_from_map(x, y, Qmap, vrt, hrz, diag1, diag2):
    vrt[x] = False
    hrz[y] = False
    diag1[x + y] = False
    diag2[x - y + 7] = False
    Qmap[x][y] = False

def check_Q(x, y, Qmap, vrt, hrz, diag1, diag2):
    if vrt[x]:
        return False
    if hrz[y]:
        return False
    if diag1[x + y]:
        return False
    if diag2[x - y + 7]:
        return False
    return True

def backtrack(start_i, start_j, cur_num, Qmap, vrt, hrz, diag1, diag2):
    if cur_num == 8:
        return True
    for i in range(start_i, W):
        first_j = 0
        if i == start_i:
            first_j = start_j
        for j in range(first_j, W):
            if not check_Q(i, j, Qmap, vrt, hrz, diag1, diag2):
                continue
            add_Q_to_map(i, j, Qmap, vrt, hrz, diag1, diag2)
            if backtrack(i+(j+1)/8, (j+1)%8, cur_num+1, Qmap, vrt, hrz, diag1, diag2):
                return True
            remove_Q_from_map(i, j, Qmap, vrt, hrz, diag1, diag2)
    return False

def print_map(Qmap):
    for i in Qmap:
        cur_line = ''
        for j in i:
            if not j:
                cur_line += '.'
            else:
                cur_line += 'Q'
        print cur_line

def main():
    N = int(get_line())
    Qmap = []
    vrt = [False] * W
    hrz = [False] * W
    diag1 = [False] * (2 * W)
    diag2 = [False] * (2 * W)
    for i in range(W):
        Qmap.append([False] * W)
    for i in range(N):
        x, y = get_line(True)
        add_Q_to_map(x, y, Qmap, vrt, hrz, diag1, diag2)
    assert backtrack(0, 0, N, Qmap, vrt, hrz, diag1, diag2)
    print_map(Qmap)

if __name__ == '__main__':
    main()
