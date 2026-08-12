class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        ans=1
        count=1
        val=0
        if len(nums)==1:
            return nums[0]
        for i in range(1,len(nums)):
            if nums[i-1]==nums[i]:
                count+=1
                if count>ans:
                    val=nums[i]
                ans=max(ans,count)
            else:
                count=1
        return val