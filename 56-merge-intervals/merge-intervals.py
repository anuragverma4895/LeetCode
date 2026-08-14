class Solution:
    def merge(self, nums: List[List[int]]) -> List[List[int]]:
        l=[]
        nums.sort()
        l.append(nums[0])

        for i in range(len(nums)):
            if l[-1][1] >=nums[i][0]:
                l[-1][1]=max(l[-1][1],nums[i][1])
            else:
                l.append(nums[i])
        return l
