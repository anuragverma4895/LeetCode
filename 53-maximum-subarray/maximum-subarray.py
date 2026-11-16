class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        sum=0
        ans=-2**31 - 1
        for x in nums:
            sum+=x
            ans=max(sum,ans)
            if(sum<=0):
                sum=0
        return ans
