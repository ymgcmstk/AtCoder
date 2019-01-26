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

W = 3
F_state = '123456780'

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def change_state(cur_state, i):
    zero_place = cur_state.find('0')
    x = zero_place % 3
    y = zero_place / 3
    next_x = x + dx[i]
    next_y = y + dy[i]
    if next_x < 0 or next_x > 2 or next_y < 0 or next_y > 2:
        return False
    next_zero = next_x + next_y * 3
    cur_state = list(cur_state)
    cur_state[next_zero], cur_state[zero_place] = cur_state[zero_place], cur_state[next_zero]
    cur_state = ''.join(cur_state)
    return cur_state

def main():
    initial_state = ''
    for i in range(W):
        for j in get_line(True):
            initial_state += str(j)
    state_queue = [(0, initial_state)]
    state_list = set([initial_state])
    while True:
        cur_step, base_state = state_queue[0]
        state_queue = state_queue[1:]
        for i in range(4):
            next_state = change_state(base_state, i)
            if next_state == False:
                continue
            if next_state == F_state:
                print cur_step + 1
                return cur_step + 1
            if next_state in state_list:
                continue
            state_list.add(next_state)
            state_queue.append((cur_step+1, next_state))

if __name__ == '__main__':
    main()
