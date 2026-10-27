class Solution:
    def frequencySort(self, nums: list[int]) -> list[int]:
        nums.sort(reverse=True)
        mp={}
        for x in nums:
            if x in mp:
                mp[x]+=1
            else:
                mp[x]=1
        nums.sort(key=lambda x:mp[x])
        return nums
            
        