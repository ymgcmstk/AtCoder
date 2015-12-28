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
        try:
            contest_name = 'VOLUME%d' % url
            url = 'http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?volumeNo=%d' % int(url)
        except:
            contest_name = url
            url = 'http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=%s' % url

    elif 'volumeNo' in url:
        contest_name = 'VOLUME' + url.split('=')[1]
    else:
        contest_name = url.split('=')[1]

    contest_path = os.path.join(AOJ_DIR, contest_name)
    mkdir_if_missing(contest_path)

    page  = urlopen(url)
    soup  = BeautifulSoup(page, 'html.parser')
    table = soup.find('table', attrs={'id': 'tableRanking'})

    for tr in table.find_all('tr', attrs={'class': 'dat'}):
        (sharptd, qlinktd) = tr.find_all('td', limit=3)[2]
        url_tail = sharptd.get('href')
        index    = url_tail.split('id=')[-1]
        q_path   = os.path.join(contest_path, index)
        mkdir_if_missing(q_path)
        if not (os.path.exists(os.path.join(q_path, INPUT_FILE_NAME)) and os.path.exists(os.path.join(q_path, OUTPUT_FILE_NAME))):
            cur_url = BASE_AOJ_URL % url_tail
            try:
                inputs, outputs = soup_prets(cur_url)
            except:
                print 'Error:', cur_url
                continue
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
    for _h2tag in soup.find_all('h2'):
        if _h2tag.string is None:
            continue
        if _h2tag.string.strip().startswith(AOJ_FIRST_INPUT_EXAMPLE):
            h2tag = _h2tag
            break
    for pretag in h2tag.find_all_next("pre", attrs={"class": "prettyprint"})[::2]:
        inputs.append(pretag.string.strip().replace(chr(13), ''))
    if len(inputs) == 0:
        for pretag in h2tag.find_all_next("pre")[::2]:
            inputs.append(pretag.string.strip().replace(chr(13), ''))
    for pretag in h2tag.find_all_next("pre", attrs={"class": "prettyprint"})[1::2]:
        outputs.append(pretag.string.strip().replace(chr(13), ''))
    if len(outputs) == 0:
        for pretag in h2tag.find_all_next("pre")[1::2]:
            outputs.append(pretag.string.strip().replace(chr(13), ''))
    return ("\n" + DELIMITER + "\n").join(inputs), ("\n" + DELIMITER + "\n").join(outputs)

if __name__ == '__main__':
    main()
