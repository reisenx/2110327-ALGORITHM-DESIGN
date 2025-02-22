import sys
N = int(sys.stdin.readline())
points = [int(e) for e in sys.stdin.readline().split()]
if(len(points) > 1):
    points[1] += points[0]
if(len(points) > 2):
    points[2] += max(points[0], points[1])
for i in range(3, N):
    points[i] += max(points[i-3], points[i-2], points[i-1])
sys.stdout.write(str(points[-1]))