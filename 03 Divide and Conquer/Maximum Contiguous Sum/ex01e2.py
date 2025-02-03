import sys
maxSum = -1e6
currentSum = 0
n = int(sys.stdin.readline())
for num in sys.stdin.readline().split():
    currentSum += int(num)
    maxSum = max(currentSum, maxSum)
    currentSum = max(0, currentSum)
sys.stdout.write(str(maxSum))