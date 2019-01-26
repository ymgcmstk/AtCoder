#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *
import os
from settings import *
import splinter
import Levenshtein
import time

def decide_file(targ_dir, targ_fname=None):
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
            return EXT2LANG[CPP_EXT], '%s.%s' % (targ_file, CPP_EXT)
        if CPP_EXT in targ_file:
            return EXT2LANG[CPP_EXT], targ_file
        for ext in EXC_STR:
            if targ_file.endswith(ext):
                return EXT2LANG[ext], targ_file
    raise Exception()

def main():
    targ_dir  = os.getcwd()
    if len(sys.argv) == 1:
        targ_lang, targ_file = decide_file(targ_dir)
    elif len(sys.argv) == 2:
        targ_lang, targ_file = decide_file(targ_dir, sys.argv[1])
    else:
        raise Exception("The number of input arguments is wrong")

    contest_name, sub_name = os.getcwd().split('/')[-2:]
    browser = splinter.Browser(BROWSER)
    # sign in
    signin_url = os.path.join(BASE_URL % contest_name, 'login')
    browser.visit(signin_url)
    browser.fill('name', USER_NAME)
    browser.fill('password', PASSWORD)
    browser.find_by_xpath('//*[@id="outer-inner"]/div[2]/div[1]/form/fieldset/div[3]/button').click()

    # submit
    submit_url = os.path.join(BASE_URL % contest_name, 'submit')
    browser.visit(os.path.join(BASE_URL % contest_name, 'submit'))
    f = open(targ_file, 'r')
    browser.fill('source_code', ''.join(f.read()).decode('utf-8'))
    f.close()
    elements = browser.find_by_xpath('//*[@id="submit-task-selector"]/option')
    for i in elements:
        if i.text.startswith(sub_name):
            i.click()
            break

    elements = browser.find_by_xpath('//select[@class="submit-language-selector"]')
    targ_num = None
    for num, i in enumerate(elements):
        if i.visible:
            targ_num = num + 1
            break
    elements = browser.find_by_xpath('//select[@class="submit-language-selector"][%d]/option' % targ_num)
    dist = float('inf')
    for i in elements:
        i_dist = Levenshtein.distance(i.text, unicode(targ_lang))
        if i_dist < dist:
            dist = i_dist
            i.click()
    browser.find_by_xpath('//*[@id="outer-inner"]/div[2]/div/form/fieldset/div[4]/button/span/span[2]').click()
    cur_status = browser.find_by_xpath('//*[@id="outer-inner"]/table/tbody/tr[1]/td[5]/span').text
    while cur_status == 'WJ' or '/' in cur_status:
        printr(cur_status)
        time.sleep(5)
        browser.reload()
        cur_status = browser.find_by_xpath('//*[@id="outer-inner"]/table/tbody/tr[1]/td[5]/span').text
    print cur_status + ' ' * 20
    browser.quit()

if __name__ == '__main__':
    print 'User name:', USER_NAME
    main()
