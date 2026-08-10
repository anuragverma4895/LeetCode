class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # nums.sort()
        # n=len(nums)
        # for i in range(1,n):
        #     if nums[i-1]==nums[i]:
        #         return True
        # return False

        # other method by using dictonary
        n=len(nums)
        freq={}
        for x in nums:
            freq[x]=freq.get(x,0)+1
        for x in nums:
            if freq[x]>1:
                return True
        return False

