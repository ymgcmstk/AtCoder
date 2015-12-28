# How to use

This repository is for AtCoder Contest and partially for Aizu Online Judge.
You have to rewrite `ROOT` on `tools/settings.py` before using this repository.

## Get test cases from the contest page
### AtCoder
To generate the directory for a contest held on AtCoder, move to `./tools` and run the script `prepare.py` like below.

`python prepare.py http://arc001.contest.atcoder.jp/`

or

`python prepare.py arc001`

Then move to the generated directory and write the code and compile it.

### Aizu Online Judge
`python prepare_aoj.py http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ALDS1`

or

`python prepare_aoj.py ALDS1`

## Test your code using test cases
You can test your compiled file by running the script `./tools/test.py`.
In my case, I write the following line on my bash_profile and run the command `actest` on the directory for each problem.

`alias actest='python /path/to/your/rep/tools/test.py'`

Then run `actest`.

## Submit your code to AtCoder
You can also submit your source code to the contest page of AtCoder automatically by running the script `./tools/submit.py`.
The script to submit your code to AOJ has not been implemented yet.
In my case, I write the following line on my bash_profile and run the command `acsub` on the directory for each problem.

`alias acsub='python /path/to/your/rep/tools/submit.py'`

Then run `acsub`.

In order to run this script without error, you need to install the following libraries.

### Prerequisites for Auto-submission
- [Splinter](https://splinter.readthedocs.org/en/latest/)
- [pylevenshtein](https://code.google.com/p/pylevenshtein/)

# Special Thanks
[elzup](http://qiita.com/elzup/items/b06c0f949cf2f60fdd43)
[ctylim](http://ctylim.hatenablog.com/entry/2015/08/30/191553)
