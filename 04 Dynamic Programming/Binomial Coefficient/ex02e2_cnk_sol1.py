import sys
C = [[0 for col in range(31)] for row in range(31)]
for n in range(31):
    for k in range(31):
        if(k == 0 or n == k):
            C[n][k] = 1
        else:
            C[n][k] = C[n-1][k] + C[n-1][k-1]
n,k = map(int, sys.stdin.readline().split())
sys.stdout.write(str(C[n][k]))