N = int(input())
prev, current = 0, 1
if(N == 0): print(prev)
else:
    for i in range(2,N+1):
        prev, current = current, prev + current
    print(current)