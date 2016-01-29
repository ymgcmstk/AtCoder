#!/usr/bin/env python
# -*- coding:utf-8 -*-
import os
# Settings
ROOT             = '/path/to/your/AtCoder/'
TOOL_DIR         = os.path.join(ROOT, 'tools')
ABC_DIR          = os.path.join(ROOT, 'ABC')
ARC_DIR          = os.path.join(ROOT, 'ARC')
OTHERS_DIR       = os.path.join(ROOT, 'Others')
TEMPLATE         = os.path.join(TOOL_DIR, 'template.cpp')
FNAME            = ['A', 'B', 'C', 'D']
INPUT_FILE_NAME  = 'input.txt'
OUTPUT_FILE_NAME = 'output.txt'
DELIMITER = "---"
BASE_URL = 'https://%s.contest.atcoder.jp/'

FIRST_INPUT_EXAMPLE = u'入力例1'

# AOJ
AOJ_DIR      = os.path.join(ROOT, 'AOJ')
BASE_AOJ_URL = 'https://judge.u-aizu.ac.jp/onlinejudge/%s&lang=jp'
AOJ_FIRST_INPUT_EXAMPLE = u'入力例'

# Auto-submission
USER_NAME = 'XXX'
PASSWORD  = 'YYY'
LANG_CPP  = 'C++11 (GCC 4.8.1)'
LANG_PY   = 'Python (2.7.3)'
BROWSER   = 'chrome'

USE_REQUESTS = True
