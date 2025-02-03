import sys
N,M = map(int, sys.stdin.readline().split())
def binarySearch(numbers, target):
    low = 0
    high = len(numbers) - 1
    ans = -1
    while(low <= high):
        mid = (low + high)//2
        if(numbers[mid] <= target):
            ans = mid
            low = mid + 1
        else:
            high = mid - 1
    return ans
temp = list(map(int, sys.stdin.readline().split()))
numbers = []
indexes = []
answers = []
for i in range(len(temp)):
    if(len(numbers) == 0 or temp[i] > numbers[-1]):
        numbers.append(temp[i])
        indexes.append(i)
    else:
        indexes[-1] = i
for num in sys.stdin.readline().split():
    ans = binarySearch(numbers, int(num))
    if(ans >= 0):
        answers.append(str(indexes[ans]))
    else:
        answers.append(str(ans))
sys.stdout.write("\n".join(answers))