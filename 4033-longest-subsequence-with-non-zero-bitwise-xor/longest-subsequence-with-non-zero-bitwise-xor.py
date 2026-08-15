class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        n=len(nums)
        if n<=0:
            return 0
        xor=0
        for x in nums:
            xor^=x
        if xor!=0:
            return n
        allzero=1
        for x in nums:
            if x!=0:
                allzero=0
                break
        if(allzero):
            return 0
        else:
            return n-1
        
