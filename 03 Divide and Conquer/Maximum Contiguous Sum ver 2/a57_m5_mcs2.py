import sys
totalSum = 0
maxSum = -1e6
currentMaxSum = 0
minSum = 1e6
currentMinSum = 0
n = int(sys.stdin.readline())
for num in sys.stdin.readline().split():
    totalSum += int(num)
    currentMaxSum += int(num)
    currentMinSum += int(num)
    maxSum = max(currentMaxSum, maxSum)
    currentMaxSum = max(0, currentMaxSum)
    minSum = min(currentMinSum, minSum)
    currentMinSum = min(0, currentMinSum)
if(maxSum < 0):
    sys.stdout.write(str(maxSum))
else:
    sys.stdout.write(str(max(maxSum, totalSum - minSum)))