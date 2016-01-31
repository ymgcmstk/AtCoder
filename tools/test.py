#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *
import sys
import subprocess
import os
from settings import *

def split_io(targ_dir):
    f = open(os.path.join(targ_dir, INPUT_FILE_NAME))
    inputs = f.read().split(DELIMITER + '\n')
    f.close()
    if not inputs[-1].endswith('\n'):
        inputs[-1] += '\n'
    f = open(os.path.join(targ_dir, OUTPUT_FILE_NAME))
    outputs = f.read().split(DELIMITER + '\n')
    f.close()
    if not outputs[-1].endswith('\n'):
        outputs[-1] += '\n'
    return inputs, outputs

def generate_str_to_exc(targ_dir, targ_fname=None):
    if targ_fname is None:
        files = os.listdir(targ_dir)
        files.sort(key=os.path.getmtime)
        files.reverse()
    else:
        files = [targ_fname]
    for targ_file in files:
        if os.path.isdir(os.path.join(targ_dir, targ_file)):
            continue
        if not '.' in targ_file:
            return ['./%s' % targ_file], '%s.%s' % (targ_file, CPP_EXT)
        for ext in EXC_STR:
            if targ_file.endswith(ext):
                return (EXC_STR[ext] % targ_file).split(), targ_file
    raise Exception()

def main():
    targ_dir  = os.getcwd()
    if len(sys.argv) == 1:
        str_to_exc, targ_file = generate_str_to_exc(targ_dir)
    elif len(sys.argv) == 2:
        str_to_exc, targ_file = generate_str_to_exc(targ_dir, sys.argv[1])
    else:
        raise Exception("The number of input arguments is wrong")

    inputs, outputs = split_io(targ_dir)
    assert len(inputs) == len(outputs)
    pass_all = True
    for i, cur_i, cur_o in zip(range(len(inputs)), inputs, outputs):
        p = subprocess.Popen(str_to_exc, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        p.stdin.write(cur_i)
        stdout_data, stderr_data = p.communicate()
        if not (stdout_data == cur_o):
            print 'stdout:'
            print stdout_data.rstrip('\n')
            if len(stderr_data) > 0:
                print '---STDERR---'
                print stderr_data.rstrip('\n')
                print '------'
            print 'answer:'
            print cur_o.rstrip('\n')
            pass_all = False
        else:
            print 'Passed TEST %d' % (i + 1)
    if os.uname()[0] == 'Darwin' and pass_all:
        p = subprocess.Popen(['cat %s | pbcopy' % os.path.join(os.getcwd(), targ_file)], shell=True)
        p.wait()
        print 'Copy %s to clipboard' % targ_file
    return

if __name__ == '__main__':
    main()
