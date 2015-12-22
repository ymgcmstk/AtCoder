#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *
import sys
import subprocess
import os
from settings import *
import splinter
import Levenshtein
import time

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
        submit()
        """
        source_name = targ_file
        if not targ_file.endswith('.py'):
            source_name += '.cpp'
        p = subprocess.Popen(['cat %s | pbcopy' % os.path.join(os.getcwd(), source_name)], shell=True)
        p.wait()
        print 'Copy %s to clipboard' % source_name
        """
    return

def submit():
    contest_name, sub_name = os.getcwd().split('/')[-2:]
    if os.path.exists(os.path.join(sub_name)) or True:
        f_name = sub_name + '.cpp'
    else:
        assert os.path.exists('%s.py' % sub_name)
        f_name = sub_name + '.py'
    browser = splinter.Browser(BROWSER)
    # sign in
    signin_url = os.path.join(BASE_URL % contest_name, 'login')
    browser.visit(signin_url)
    browser.fill('name', USER_NAME)
    browser.fill('password', PASSWORD)
    browser.find_by_xpath('//*[@id="outer-inner"]/div[2]/div[1]/form/fieldset/div[3]/button').click()

    # submit
    submit_url = os.path.join(BASE_URL % contest_name, 'submit')
    browser.find_by_xpath('//*[@id="outer-inner"]/ul/li[3]/a/span/span[2]').click()
    f = open(f_name, 'r')
    browser.fill('source_code', ''.join(f.read()))
    f.close()
    elements = browser.find_by_xpath('//*[@id="submit-task-selector"]/option')
    for i in elements:
        if i.text.startswith(sub_name):
            i.click()
            break
    elements = browser.find_by_xpath('//*[@id="submit-language-selector-1009"]/option')
    dist = float('inf')
    for i in elements:
        if f_name.startswith('py'):
            i_dist = Levenshtein.distance(i.text, unicode(LANG_PY))
        else:
            i_dist = Levenshtein.distance(i.text, unicode(LANG_CPP))
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

if __name__ == '__main__':
    main()
