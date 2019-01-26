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

def main():
    # http://arc001.contest.atcoder.jp/
    try:
        url = sys.argv[1]
    except IndexError:
        print("input contest url:")
        url = input()

    if not url.startswith('http'):
        url = url.lower()
        url = BASE_URL % url
    elif not url.endswith('/'):
        url += '/'

    m = re.search('(https?://)(?P<name>.*)\.contest?', url)
    contest_name = m.group('name')
    if 'arc' in contest_name:
        contest_path = os.path.join(ARC_DIR, contest_name)
    elif 'abc' in contest_name:
        contest_path = os.path.join(ABC_DIR, contest_name)
    else:
        contest_path = os.path.join(OTHERS_DIR, contest_name)
    mkdir_if_missing(contest_path)

    if USE_REQUESTS:
        session = requests.session()
        params = {
            'name': USER_NAME,
            'password': PASSWORD,
        }
        session.post(os.path.join(url, "login"), params)
        page = session.get(os.path.join(url, "assignments")).text
    else:
        session = None
        page  = urlopen(os.path.join(url, "assignments"))

    soup  = BeautifulSoup(page, 'html.parser')
    if "Join in" in str(soup):
        textdump('test.txt', [str(soup)])
        print "Please join in the contest."
        exit()
    if not "Time limit" in str(soup):
        print "Please wait until the contest starts."
        exit()
    table = soup.find('table', attrs={'class': 'table-wb'}).find('tbody')

    for tr in table.find_all('tr'):
        (sharptd, qlinktd) = tr.find_all('td', limit=2)
        index  = sharptd.text
        q_path = os.path.join(contest_path, index)
        mkdir_if_missing(q_path)
        url_tail = qlinktd.find('a').get('href')
        if not (os.path.exists(os.path.join(q_path, INPUT_FILE_NAME)) and os.path.exists(os.path.join(q_path, OUTPUT_FILE_NAME))):
            pickle_path = os.path.join(q_path, PICKLE_FILE_NAME)
            inputs, outputs = soup_prets(url + url_tail[1:], session, pickle_path)
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
            copy_templates(q_path, index)
        else:
            print("already exists: f_path")

def copy_templates(q_path, index):
    for temp_ext, org_file in TEMPLATES.iteritems():
        template_file = os.path.join(q_path, '%s.%s' % (index, temp_ext))
        if not os.path.exists(template_file):
            shutil.copyfile(os.path.join(TEMPLATE_DIR, org_file), template_file)

def soup_prets(url, session, pickle_path):
    if USE_REQUESTS:
        page = session.get(url).text
    else:
        page = urlopen(url)
    soup = BeautifulSoup(page, 'html.parser')
    pickledump(pickle_path, soup)
    inputs = []
    outputs = []
    for _h3tag in soup.find_all('h3'):
        # print predict_charset(' '.join(_h3tag.strings))
        # print _h3tag.strings
        # import ipdb
        # ipdb.set_trace()
        if ' '.join(_h3tag.strings).replace(' ', '') == FIRST_INPUT_EXAMPLE:
            h3tag = _h3tag
            break
    for pretag in h3tag.find_all_next("pre", attrs={"class": "prettyprint"})[::2]:
        inputs.append(pretag.string.strip().replace(chr(13), ''))
    if len(inputs) == 0:
        for pretag in h3tag.find_all_next("pre")[::2]:
            try:
                inputs.append(pretag.string.strip().replace(chr(13), ''))
            except:
                inputs.append(pretag.text.strip().replace(chr(13), ''))
    for pretag in h3tag.find_all_next("pre", attrs={"class": "prettyprint"})[1::2]:
        outputs.append(pretag.string.strip().replace(chr(13), ''))
    if len(outputs) == 0:
        for pretag in h3tag.find_all_next("pre")[1::2]:
            outputs.append(pretag.string.strip().replace(chr(13), ''))
    return ("\n" + DELIMITER + "\n").join(inputs), ("\n" + DELIMITER + "\n").join(outputs)

if __name__ == '__main__':
    main()
