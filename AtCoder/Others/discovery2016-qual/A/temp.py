import sys
n = int(sys.stdin.readline())
targ_str = "DiscoPresentsDiscoveryChannelProgrammingContest2016"
while len(targ_str) > 0:
    print targ_str[:n]
    targ_str = targ_str[n:]
