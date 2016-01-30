#!/usr/bin/env python
# -*- coding:utf-8 -*-
from mytoolbox import *
import os
from settings import *
import splinter
import Levenshtein
import time

def main():
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
    browser.visit(os.path.join(BASE_URL % contest_name, 'submit'))
    f = open(f_name, 'r')
    # browser.fill('source_code', remove_non_ascii(''.join(f.read()))) # TODO
    browser.fill('source_code', ''.join(f.read()).decode('utf-8').encode('utf-8')) # TODO
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
    browser.quit()
if __name__ == '__main__':
    main()
