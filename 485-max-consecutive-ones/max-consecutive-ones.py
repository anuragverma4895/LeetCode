class Solution:
    def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
        ans=0
        sum=0
        for x in nums:
            if x==1:
                sum+=x
            else:
                sum=0
            ans=max(sum,ans)
        return ans
                