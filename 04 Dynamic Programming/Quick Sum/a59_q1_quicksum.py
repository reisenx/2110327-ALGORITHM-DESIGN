import sys
N,M,K = [int(e) for e in sys.stdin.readline().split()]
A = []
P = [[0 for _ in range(M)] for _ in range(N)]
for _ in range(N):
    row = [int(e) for e in sys.stdin.readline().split()]
    A.append(row)

P[0][0] = A[0][0]
for j in range(1,M):
    P[0][j] = P[0][j-1] + A[0][j]
for i in range(1,N):
    P[i][0] = P[i-1][0] + A[i][0]
    for j in range(1,M):
        P[i][j] = P[i-1][j] + P[i][j-1] - P[i-1][j-1] + A[i][j]

for _ in range(K):
    r1, c1, r2, c2 = [int(e) for e in sys.stdin.readline().split()]
    sum = P[r2][c2]
    if(r1 > 0): sum -= P[r1-1][c2]
    if(c1 > 0): sum -= P[r2][c1-1]
    if(r1 > 0 and c1 > 0): sum += P[r1-1][c1-1]
    sys.stdout.write(str(sum) + '\n')