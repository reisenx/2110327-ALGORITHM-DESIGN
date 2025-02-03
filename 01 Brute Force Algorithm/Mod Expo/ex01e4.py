import sys
X,N,K = map(int, sys.stdin.readline().split())
sys.stdout.write(str(pow(X,N,K)))