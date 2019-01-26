A = raw_input()
A = A.split()
p = ''
for i in A:
    if i == 'Left':
        p += '< '
    elif i == 'Right':
        p += '> '
    else:
        p += 'A '
p = p[:-1]
print p
