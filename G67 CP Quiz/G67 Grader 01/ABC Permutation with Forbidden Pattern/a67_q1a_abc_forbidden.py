import sys
N,a,b,c = map(int, sys.stdin.readline().split())
M = int(sys.stdin.readline())
wordList = []
banWords = [False] * 9
for _ in range(M):
    ban = sys.stdin.readline().strip()
    banWords[ 3*(ord(ban[0]) - ord('A')) + (ord(ban[1]) - ord('A')) ] = True

def permutation(word, step, a, b, c):
    if(step == N):
        wordList.append(word)
        return
    else:
        prev = '\0'
        if(step > 0):
            prev = word[-1]
        if(a > 0 and (not (prev == 'A' and banWords[0])) and (not (prev == 'B' and banWords[3])) and (not (prev == 'C' and banWords[6]))):
            permutation(word + 'A', step + 1, a - 1, b, c)
        if(b > 0 and (not (prev == 'A' and banWords[1])) and (not (prev == 'B' and banWords[4])) and (not (prev == 'C' and banWords[7]))):
            permutation(word + 'B', step + 1, a, b - 1, c)
        if(c > 0 and (not (prev == 'A' and banWords[2])) and (not (prev == 'B' and banWords[5])) and (not (prev == 'C' and banWords[8]))):
            permutation(word + 'C', step + 1, a, b, c - 1)

permutation("", 0, a, b, c)
sys.stdout.write(str(len(wordList)) + "\n")
sys.stdout.write("\n".join(wordList))