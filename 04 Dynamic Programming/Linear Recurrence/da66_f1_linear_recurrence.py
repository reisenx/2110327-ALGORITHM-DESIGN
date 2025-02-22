import sys
k,n = [int(e) for e in sys.stdin.readline().split()]
c = [int(e) for e in sys.stdin.readline().split()]
a = [int(e) for e in sys.stdin.readline().split()]
R = [-1 for _ in range(n+1)]

def linearRecurrence(n,k):
    if(R[n] != -1):
        return R[n]
    if(n < k):
        R[n] = a[n] % 32717
        return R[n]
    result = 0
    for i in range(k):
        term = ((c[i] % 32717) * (linearRecurrence(n-i-1, k) % 32717)) % 32717
        result = ((result % 32717) + (term % 32717)) % 32717
    R[n] = result
    return R[n]

sys.stdout.write(str(linearRecurrence(n,k)))