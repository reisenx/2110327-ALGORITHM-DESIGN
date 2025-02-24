import sys
N = int(sys.stdin.readline())
prev, current = [], []
for i in range(N):
    prev = current
    current = [int(e) for e in sys.stdin.readline().split()]
    if(i > 0):
        for j in range(len(current)):
            if(j == 0):
                current[j] += prev[j]
            elif(j == i):
                current[j] += prev[j-1]
            else:
                current[j] += max(prev[j-1], prev[j])
sys.stdout.write(str(max(current)))