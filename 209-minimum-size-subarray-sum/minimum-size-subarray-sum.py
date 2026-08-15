class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        count=0
        sum=0
        ans=1000000000
        j=0
        for x in nums:
            sum+=x
            count+=1
            if sum>=target :
                ans=min(ans,count)
            while sum>=target :
                sum-=nums[j]
                j+=1
                count-=1
                if sum>=target:
                    ans=min(ans,count)
        if ans==1000000000:
            return 0
        return ans


            
