import sys
N = []
for i in range(3):
    N.append([float(sys.stdin.readline()), i])
rank = range(3)
N = sorted(N, key=lambda x:x[0])
for i in range(3):
    rank[N[i][1]] = i+1
for i in rank:
    print 4 - i
