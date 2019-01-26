#!/usr/bin/env python
# -*- coding:utf-8 -*-

"""
This code is based on http://qiita.com/elzup/items/b06c0f949cf2f60fdd43, provided by elzup.
"""

from mytoolbox import *
from bs4 import BeautifulSoup
import sys
import os
import re
from settings import *
set_debugger()

if USE_REQUESTS:
    try:
        import requests
    except:
        USE_REQUESTS = False
if not USE_REQUESTS:
    from urllib.request import urlopen

def copy_templates(q_path, index):
    for temp_ext, org_file in TEMPLATES.iteritems():
        template_file = os.path.join(q_path, '%s.%s' % (index, temp_ext))
        if not os.path.exists(template_file):
            shutil.copyfile(os.path.join(TEMPLATE_DIR, org_file), template_file)

def soup_prets(page):
    soup = BeautifulSoup(page, 'html.parser')
    inputs = []
    outputs = []
    for _h3tag in soup.find_all('h3'):
        if ' '.join(_h3tag.strings).replace(' ', '') == FIRST_INPUT_EXAMPLE:
            h3tag = _h3tag
            break
    for pretag in h3tag.find_all_next("pre", attrs={"class": "prettyprint"})[::2]:
        inputs.append(pretag.string.strip().replace(chr(13), ''))
    if len(inputs) == 0:
        for pretag in h3tag.find_all_next("pre")[::2]:
            inputs.append(pretag.string.strip().replace(chr(13), ''))
    for pretag in h3tag.find_all_next("pre", attrs={"class": "prettyprint"})[1::2]:
        outputs.append(pretag.string.strip().replace(chr(13), ''))
    if len(outputs) == 0:
        for pretag in h3tag.find_all_next("pre")[1::2]:
            outputs.append(pretag.string.strip().replace(chr(13), ''))
    return ("\n" + DELIMITER + "\n").join(inputs), ("\n" + DELIMITER + "\n").join(outputs)

def prepare_with_html(page_name):
    f = open(page_name)
    page = f.read()
    f.close()
    inputs, outputs = soup_prets(page)
    # f_path = os.path.join(q_path, INPUT_FILE_NAME)
    f_path = INPUT_FILE_NAME
    f = open(f_path, "w")
    f.write(inputs)
    f.close()
    print("generate input > " + f_path)
    # f_path = os.path.join(q_path, OUTPUT_FILE_NAME)
    f_path = OUTPUT_FILE_NAME
    f = open(f_path, "w")
    f.write(outputs)
    f.close()
    print("generate input > " + f_path)
    copy_templates('.', os.getcwd().split('/')[-1])

if __name__ == '__main__':
    for fname in os.listdir('.'):
        if fname.endswith('.html'):
            prepare_with_html(fname)
            break
