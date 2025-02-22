import sys
n,a,b,c = [int(e) for e in sys.stdin.readline().split()]
# Calculate maximum pieces that can be cutted in each length
# -1 means it is impossible to be cutted
maxPieces = [-1 for _ in range(n+1)]
# At length = 0 can be cutted into 0 pieces
maxPieces[0] = 0
for i in range(1, n+1):
    # Can be cut into a rope with length 'a'
    if(i >= a and maxPieces[i-a] >= 0):
        maxPieces[i] = max(maxPieces[i], maxPieces[i-a] + 1)
    # Can be cut into a rope with length 'b'
    if(i >= b and maxPieces[i-b] >= 0):
        maxPieces[i] = max(maxPieces[i], maxPieces[i-b] + 1)
    # Can be cut into a rope with length 'c'
    if(i >= c and maxPieces[i-c] >= 0):
        maxPieces[i] = max(maxPieces[i], maxPieces[i-c] + 1)
# Output
sys.stdout.write(str(maxPieces[n]))