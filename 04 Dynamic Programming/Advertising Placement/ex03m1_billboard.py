import sys
N = int(sys.stdin.readline())
totalCustomer = [int(e) for e in sys.stdin.readline().split()]
for i in range(N):
    if(i > 2):
        totalCustomer[i] += max(totalCustomer[i-3], totalCustomer[i-2])
    elif(i == 2):
        totalCustomer[2] += totalCustomer[0]
sys.stdout.write(str(max(totalCustomer[-2], totalCustomer[-1])))