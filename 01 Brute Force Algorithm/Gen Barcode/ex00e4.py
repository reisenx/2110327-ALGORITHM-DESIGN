import sys
A,B = map(int, sys.stdin.readline().split())
nums_list = []
def recursive(nums, ones):
    if(len(nums) == B):
        if(ones == A):
            nums_list.append(nums)
        return
    else:
        recursive(nums + '0', ones)
        recursive(nums + '1', ones + 1)
recursive("", 0)
sys.stdout.write("\n".join(nums_list))