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

def split(preorder, inorder):
    if len(preorder) == 0:
        return
    for num, i in enumerate(inorder):
        if i == preorder[0]:
            n = num
            break
    split(preorder[1:n+1], inorder[:n]) # left tree
    split(preorder[n+1:], inorder[n+1:]) # right tree
    print preorder[0],

def main():
    N = int(get_line())
    preorder = get_line(True)
    inorder  = get_line(True)
    split(preorder, inorder)


if __name__ == '__main__':
    main()
