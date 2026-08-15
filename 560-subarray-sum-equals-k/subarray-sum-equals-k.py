class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mp={}
        mp[0]=1
        sum=0
        ans=0
        for x in nums:
            sum+=x
            if sum-k in mp:
                ans+=mp[sum-k]
            mp[sum]=mp.get(sum,0)+1
        return ans