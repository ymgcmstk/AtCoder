#!/usr/bin/env python
# -*- coding:utf-8 -*-

"""
This code is based on http://qiita.com/elzup/items/b06c0f949cf2f60fdd43, provided by elzup.
"""

from mytoolbox import *
from urllib import urlopen
from bs4 import BeautifulSoup
import sys
import os
import re
from settings import *

def main():
    # http://arc001.contest.atcoder.jp/
    try:
        url = sys.argv[1]
    except IndexError:
        print("input contest url:")
        url = input()

    if not url.startswith('http'):
        url = 'http://%s.contest.atcoder.jp' % url

    m = re.search('(https?://)(?P<name>.*)\.contest?', url)
    contest_name = m.group('name')
    if 'arc' in contest_name:
        contest_path = os.path.join(ARC_DIR, contest_name)
    elif 'abc' in contest_name:
        contest_path = os.path.join(ABC_DIR, contest_name)
    else:
        contest_path = os.path.join(OTHERS_DIR, contest_name)
    mkdir_if_missing(contest_path)

    page  = urlopen(url + "assignments")
    soup  = BeautifulSoup(page, 'html.parser')
    table = soup.find('table', attrs={'class': 'table-wb'}).find('tbody')

    for tr in table.find_all('tr'):
        (sharptd, qlinktd) = tr.find_all('td', limit=2)
        index  = sharptd.text
        q_path = os.path.join(contest_path, index)
        mkdir_if_missing(q_path)
        url_tail = qlinktd.find('a').get('href')
        if not (os.path.exists(os.path.join(q_path, INPUT_FILE_NAME)) and os.path.exists(os.path.join(q_path, OUTPUT_FILE_NAME))):
            inputs, outputs = soup_prets(url + url_tail[1:])
            f_path = os.path.join(q_path, INPUT_FILE_NAME)
            f = open(f_path, "w")
            f.write(inputs)
            f.close()
            print("generate input > " + f_path)
            f_path = os.path.join(q_path, OUTPUT_FILE_NAME)
            f = open(f_path, "w")
            f.write(outputs)
            f.close()
            print("generate input > " + f_path)
            cpp_file = os.path.join(q_path, '%s.cpp' % index)
            if not os.path.exists(cpp_file):
                shutil.copyfile(TEMPLATE, cpp_file)
        else:
            print("already exists: f_path")

def soup_prets(url):
    page = urlopen(url)
    soup = BeautifulSoup(page, 'html.parser')
    inputs = []
    outputs = []
    for pretag in soup.find_all("pre", attrs={"class": "prettyprint"})[::2]:
        inputs.append(pretag.string.strip().replace(chr(13), ''))
    for pretag in soup.find_all("pre", attrs={"class": "prettyprint"})[1::2]:
        outputs.append(pretag.string.strip().replace(chr(13), ''))
    return ("\n" + DELIMITER + "\n").join(inputs), ("\n" + DELIMITER + "\n").join(outputs)

if __name__ == '__main__':
    main()
