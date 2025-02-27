import sys
n,m = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))

for _ in range(m):
    idx = [int(e) - 1 for e in sys.stdin.readline().split()]
    isSorted = True
    isStable = True
    
    for i in range(1, n):
        if(A[idx[i]] < A[idx[i - 1]]):
            isSorted = False
            isStable = False
            break
        if(A[idx[i]] == A[idx[i - 1]] and idx[i] < idx[i - 1]):
            isStable = False
    
    if(isSorted):
        sys.stdout.write("1 ")
    else:
        sys.stdout.write("0 ")
    if(isStable):
        sys.stdout.write("1\n")
    else:
        sys.stdout.write("0\n")
