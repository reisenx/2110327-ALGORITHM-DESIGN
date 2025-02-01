import sys
n,k = map(int, sys.stdin.readline().split())
nums_list = []
def recursive(nums, ones, done):
    if(ones >= k):
        done = True
    if(len(nums) == n):
        if(done):
            nums_list.append(nums)
        return
    else:
        recursive(nums + '0', 0, done)
        recursive(nums + '1', ones + 1, done)
recursive("", 0, False)
sys.stdout.write("\n".join(nums_list))