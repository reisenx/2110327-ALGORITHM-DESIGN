import sys
n = int(sys.stdin.readline())
table = [[int(num) for num in sys.stdin.readline().split()] for _ in range(n)]

def maxDiagonalSum(x,y):
    maxSum = table[x][y]
    currentSum = table[x][y]
    loops = min(n - x, n - y)
    for i in range(1, loops):
        currentSum = max(currentSum + table[x + i][y + i], table[x + i][y + i])
        maxSum = max(maxSum, currentSum)
    return maxSum

maxSum = maxDiagonalSum(0,0)
for i in range(1,n):
    maxSum = max(maxSum, maxDiagonalSum(0, i))
    maxSum = max(maxSum, maxDiagonalSum(i, 0))
sys.stdout.write(str(maxSum))