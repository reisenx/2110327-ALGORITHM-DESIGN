import sys
N,M = map(int, sys.stdin.readline().split())
def binarySearch(numbers, target):
    low = 0
    high = len(numbers) - 1
    ans = -1
    while(low <= high):
        mid = (low + high)//2
        if(numbers[mid] <= target):
            ans = numbers[mid]
            low = mid + 1
        else:
            high = mid - 1
    return ans
numbers = list(map(int, sys.stdin.readline().split()))
answers = [str(binarySearch(numbers, int(num))) 
            for num in sys.stdin.readline().split()]
sys.stdout.write("\n".join(answers))