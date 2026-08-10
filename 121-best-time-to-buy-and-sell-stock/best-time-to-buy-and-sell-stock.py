class Solution:
    def maxProfit(self, nums: List[int]) -> int:
        n=len(nums)
        a=nums[0]
        ans=0
        for i in range(1,n):
            a=min(nums[i],a)
            ans=max(ans,nums[i]-a)
        return ans
