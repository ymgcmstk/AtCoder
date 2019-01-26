import sys

def main():
    S = sys.stdin.readline()
    T = sys.stdin.readline()
    for i, j in zip(S, T):
        S = set([i, j])
        if len(S) == 1:
            continue
        if '@' in S:
            tempflg = False
            for atc in 'atcoder':
                if atc in S:
                    tempflg = True
                    break
            if tempflg:
                continue
        print "You will lose"
        return
    print "You can win"
    return

if __name__ == '__main__':
    main()
