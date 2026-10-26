class Solution:
    def containsNearbyDuplicate(self, nums: list[int], k: int) -> bool:
        # TLE
        # for i in range(len(nums)):
        #     for j in range(i+1,len(nums)):
        #         if nums[i]==nums[j] and abs(i-j)<=k:
        #             return True
        # return 
        
        mp={}
        for i in range(len(nums)):
            if nums[i] in mp:
                if abs(mp[nums[i]]-i)<=k:
                    return True
                else:
                    mp[nums[i]]=i
            else:
                mp[nums[i]]=i
        return False