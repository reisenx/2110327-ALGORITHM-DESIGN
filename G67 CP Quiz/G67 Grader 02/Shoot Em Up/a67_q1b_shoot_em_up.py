import sys
allMove = []
step, ceiling, initial = map(int, sys.stdin.readline().split())

def recur(move, step, current):
    if(current <= 0 or current > ceiling):
        return
    if(step == 0):
        allMove.append(move)
        return
    
    recur(move + 'D', step - 1, current - 1)
    recur(move + 'S', step - 1, current)
    recur(move + 'U', step - 1, current + 1)

recur("", step, initial)
sys.stdout.write('\n'.join(allMove))
