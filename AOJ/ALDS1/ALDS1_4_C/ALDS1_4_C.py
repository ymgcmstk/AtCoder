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

char2int = {
    'A': 0,
    'C': 1,
    'G': 2,
    'T': 3
}
int2char = {i: j for j, i in char2int.iteritems()}

def str2int(targ_str):
    cur_int = 1
    for i in targ_str:
        cur_int *= 4
        cur_int += char2int[i]
    return cur_int

def int2str(cur_int):
    cur_str = ''
    while cur_int > 0:
        cur_str  = int2char[cur_int % 4] + cur_str
        cur_int /= 4
    assert cur_str[0] == 'C'
    return cur_str[1:]

def test():
    test_str = 'ACGTTA'
    assert int2str(str2int(test_str)) == test_str
    test_str = 'CCGTTA'
    assert int2str(str2int(test_str)) == test_str

LIST_LEN = 10000

def main():
    N = int(get_line())
    cur_list = range(LIST_LEN)
    for i in range(N):
        cur_line = get_line().split()
        if cur_line[0] == 'insert':
            cur_ind = str2int(cur_line[1]) % LIST_LEN
            if isinstance(cur_list[cur_ind], int):
                cur_list[cur_ind] = [cur_line[1]]
            else:
                cur_list[cur_ind].append([cur_line[1]])
        elif cur_line[0] == 'find':
            cur_ind = str2int(cur_line[1]) % LIST_LEN
            if isinstance(cur_list[cur_ind], int):
                print 'no'
                continue
            flg = True
            for i in cur_list[cur_ind]:
                if i == cur_line[1]:
                    print 'yes'
                    flg = False
                    break
            if flg:
                print 'no'
        else:
            raise Exception()

if __name__ == '__main__':
    main()
