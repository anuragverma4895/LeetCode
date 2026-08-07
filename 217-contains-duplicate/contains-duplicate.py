class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        n=len(nums)
        freq={}
        for i in range(n):
            freq[nums[i]]=freq.get(nums[i],0)+1
        for values in freq.values():
            if values>1:
                return True
        return False