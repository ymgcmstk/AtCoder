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

def main():
    targ_dir  = os.getcwd()
    targ_file = os.path.basename(targ_dir)
    if not os.path.exists(os.path.join(targ_dir, targ_file)):
        assert os.path.exists(os.path.join(targ_dir, '%s.py' % targ_file))
        targ_file += '.py'

    inputs, outputs = split_io(targ_dir)
    assert len(inputs) == len(outputs)
    pass_all = True
    for i, cur_i, cur_o in zip(range(len(inputs)), inputs, outputs):
        p = subprocess.Popen(['./%s' % targ_file], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        p.stdin.write(cur_i)
        stdout_data, stderr_data = p.communicate()
        if not (stdout_data == cur_o):
            print 'stdout:'
            print stdout_data.rstrip('\n')
            print 'output:'
            print cur_o.rstrip('\n')
            pass_all = False
        else:
            print 'Passed TEST %d' % (i + 1)
    if os.uname()[0] == 'Darwin' and pass_all:
        source_name = targ_file
        if not targ_file.endswith('.py'):
            source_name += '.cpp'
        p = subprocess.Popen(['cat %s | pbcopy' % os.path.join(os.getcwd(), source_name)], shell=True)
        p.wait()
        print 'Copy %s to clipboard' % source_name
    return

if __name__ == '__main__':
    main()
