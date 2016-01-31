#!/usr/bin/env python
# -*- coding:utf-8 -*-
import os

# Overall Settings
ROOT             = '/path/to/this/root'
TOOL_DIR         = os.path.join(ROOT, 'tools')
TEMPLATE_DIR     = os.path.join(TOOL_DIR, 'templates')
TEMPLATES        = {'py': 'template.py', 'cpp': 'template.cpp'}
INPUT_FILE_NAME  = 'input.txt'
OUTPUT_FILE_NAME = 'output.txt'
DELIMITER        = '---'
USE_REQUESTS     = True

# AtCoder Settings
AC_ROOT             = os.path.join(ROOT, 'AtCoder')
ABC_DIR             = os.path.join(AC_ROOT, 'ABC')
ARC_DIR             = os.path.join(AC_ROOT, 'ARC')
OTHERS_DIR          = os.path.join(AC_ROOT, 'Others')
BASE_URL            = 'https://%s.contest.atcoder.jp/'
FIRST_INPUT_EXAMPLE = u'入力例1'

# Auto-submission Settings for AtCoder
USER_NAME = 'XXX'
PASSWORD  = 'YYY'
LANG      = {'py': 'Python (2.7.3)', 'cpp': 'C++11 (GCC 4.8.1)'}
BROWSER   = 'chrome'

# AOJ Settings
AOJ_ROOT                = os.path.join(ROOT, 'AOJ')
BASE_AOJ_URL            = 'https://judge.u-aizu.ac.jp/onlinejudge/%s&lang=jp'
AOJ_FIRST_INPUT_EXAMPLE = u'入力例'

# Assertions
assert set(TEMPLATES.keys()) == set(LANG.keys())
for ext, fname in TEMPLATES.iteritems():
    assert fname.endswith('.' + ext)
    assert os.path.exists(os.path.join(TEMPLATE_DIR, fname)
