This repository is for AtCoder Contest and partially for Aizu Online Judge.

To generate the directory for a contest, move to `./tools` and run the script `prepare.py` like below.

`python prepare.py http://arc001.contest.atcoder.jp/`

Then move to the generated directory and write the code and compile it.

You can test your compiled file by running the script `./tools/test.py`.
In my case, I write the following line on my bash_profile and run the command `actest` on the directory for each problem.

`alias actest='python /path/to/your/rep/tools/test.py'`

You can also submit your source code to the contest page automatically by running the script `./tools/submit.py`.
In my case, I write the following line on my bash_profile and run the command `acsub` on the directory for each problem.

`alias acsub='python /path/to/your/rep/tools/submit.py'`

In order to run this script without error, you need to install the following libraries.


# Prerequisites for Auto-submission
- [Splinter](https://splinter.readthedocs.org/en/latest/)
- [pylevenshtein](https://code.google.com/p/pylevenshtein/)

# Special Thanks
[elzup](http://qiita.com/elzup/items/b06c0f949cf2f60fdd43)
[ctylim](http://ctylim.hatenablog.com/entry/2015/08/30/191553)
