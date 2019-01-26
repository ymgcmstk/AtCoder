#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *

def predict_charset (targ_str):
    targ_charsets = ['utf-8', 'cp932', 'euc-jp', 'iso-2022-jp']
    for targ_charset in targ_charsets:
        try:
            targ_str.decode(targ_charset)
            return targ_charset
        except UnicodeDecodeError:
            pass
    return None

def remove_non_ascii(targ_str, charset=None):
    if charset is not None:
        targ_str = targ_str.decode(charset)
    return ''.join([x for x in targ_str if ord(x) < 256]).encode('ascii')

def main():
    a = remove_non_ascii(u'あいuasdあ')
    print a, type(a)
    return

if __name__ == '__main__':
    main()
