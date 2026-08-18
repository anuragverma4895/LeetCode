class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n=len(nums)
        sum=0
        for x in nums:
            sum+=x
        n=n*(n+1)/2
        ans=n-sum
        return int(ans)