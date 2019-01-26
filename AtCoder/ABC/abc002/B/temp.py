import sys
a = sys.stdin.readline()
for i in ['a', 'i', 'u', 'e', 'o']:
    a = a.replace(i, '')
print a,
