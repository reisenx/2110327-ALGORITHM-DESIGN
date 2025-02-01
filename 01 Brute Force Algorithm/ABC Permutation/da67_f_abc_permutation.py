import sys

ans = []
def recursive(word, n, a, b, c):
    if(n == 0):
        ans.append(word)
        return
    if(a > 0):
        recursive(word + 'A', n-1, a-1, b, c)
    if(b > 0):
        recursive(word + 'B', n-1, a, b-1, c)
    if(c > 0):
        recursive(word + 'C', n-1, a, b, c-1)

N,A,B,C = map(int, sys.stdin.readline().split())
recursive("", N, A, B, C)
sys.stdout.write(str(len(ans)) + "\n")
sys.stdout.write("\n".join(ans))