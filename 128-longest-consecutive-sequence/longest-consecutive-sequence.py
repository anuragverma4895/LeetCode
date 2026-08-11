class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums.sort()
        if len(nums)==0:
            return 0
        ans=1
        count=1
        for i in range(1,len(nums)):
            if nums[i-1]==nums[i]:
                continue
            if nums[i-1]+1==nums[i]:
                count+=1
            else:
                count=1
            ans=max(ans,count)
        return ans
