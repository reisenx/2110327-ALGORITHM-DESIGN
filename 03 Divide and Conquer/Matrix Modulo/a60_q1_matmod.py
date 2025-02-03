import sys
n,k = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))
result = [1,0,0,1]
while(n > 0):
    if(n % 2 == 1):
        R0 = ((result[0]*A[0]) % k) + ((result[1]*A[2]) % k) % k
        R1 = ((result[0]*A[1]) % k) + ((result[1]*A[3]) % k) % k
        R2 = ((result[2]*A[0]) % k) + ((result[3]*A[2]) % k) % k
        R3 = ((result[2]*A[1]) % k) + ((result[3]*A[3]) % k) % k
        result = [R0 % k, R1 % k, R2 % k, R3 % k]
    A0 = ((A[0]*A[0]) % k) + ((A[1]*A[2]) % k) % k
    A1 = ((A[0]*A[1]) % k) + ((A[1]*A[3]) % k) % k
    A2 = ((A[2]*A[0]) % k) + ((A[3]*A[2]) % k) % k
    A3 = ((A[2]*A[1]) % k) + ((A[3]*A[3]) % k) % k
    A = [A0, A1, A2, A3]
    n //= 2
sys.stdout.write(" ".join([str(num) for num in result]))
