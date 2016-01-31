#!/usr/bin/env python
# -*- coding:utf-8 -*-
import os

# Overall Settings
ROOT             = '/Users/yamaguchi/myproject/AtCoder'
TOOL_DIR         = os.path.join(ROOT, 'tools')
CPP_EXT          = 'cpp'
TEMPLATE_DIR     = os.path.join(TOOL_DIR, 'templates')
TEMPLATES        = {'py': 'template.py', CPP_EXT: 'template.%s' % CPP_EXT}
INPUT_FILE_NAME  = 'input.txt'
OUTPUT_FILE_NAME = 'output.txt'
DELIMITER        = '---'
USE_REQUESTS     = True

# Test Settings
EXC_STR = {'py': '/usr/bin/python ./%s'}

# AtCoder Settings
AC_ROOT             = os.path.join(ROOT, 'AtCoder')
ABC_DIR             = os.path.join(AC_ROOT, 'ABC')
ARC_DIR             = os.path.join(AC_ROOT, 'ARC')
OTHERS_DIR          = os.path.join(AC_ROOT, 'Others')
BASE_URL            = 'https://%s.contest.atcoder.jp/'
FIRST_INPUT_EXAMPLE = u'入力例1'

# Auto-submission Settings for AtCoder
USER_NAME = 'gdgdgutta'
PASSWORD  = 'masataka'
EXT2LANG  = {'py': 'Python (2.7.3)', CPP_EXT: 'C++11 (GCC 4.8.1)'}
BROWSER   = 'chrome'

# AOJ Settings
AOJ_ROOT                = os.path.join(ROOT, 'AOJ')
BASE_AOJ_URL            = 'http://judge.u-aizu.ac.jp/onlinejudge/%s&lang=jp'
AOJ_FIRST_INPUT_EXAMPLE = u'入力例'

# Assertions
assert set(TEMPLATES.keys()) == set(EXT2LANG.keys())
for ext, fname in TEMPLATES.iteritems():
    assert fname.endswith('.' + ext)
    # assert os.path.exists(os.path.join(TEMPLATE_DIR, fname))
