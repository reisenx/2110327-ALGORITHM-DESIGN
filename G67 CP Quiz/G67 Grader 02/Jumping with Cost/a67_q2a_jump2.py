import sys

n,k = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))
b = list(map(int, sys.stdin.readline().split()))

bestScore = [0] * n
bestScore[0] = a[0]

for i in range(1, min(k, n)):
    bestJump = -sys.maxsize - 1
    for j in range(i):
        bestJump = max(bestJump, bestScore[i - j - 1] - b[j])
    bestScore[i] = a[i] + bestJump

for i in range(k, n):
    bestJump = -sys.maxsize - 1
    for j in range(k):
        bestJump = max(bestJump, bestScore[i - j - 1] - b[j])
    bestScore[i] = a[i] + bestJump

sys.stdout.write(str(bestScore[-1]))

