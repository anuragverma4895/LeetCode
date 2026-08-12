class Solution:
    def majorityElement(self, nums: List[int]) -> int:

        # nums.sort()
        # ans=1
        # count=1
        # val=0
        # if len(nums)==1:
        #     return nums[0]
        # for i in range(1,len(nums)):
        #     if nums[i-1]==nums[i]:
        #         count+=1
        #         if count>ans:
        #             val=nums[i]
        #         ans=max(ans,count)
        #     else:
        #         count=1
        # return val

        # # other method
        # n=len(nums)
        # freq={}
        # for x in nums:
        #     freq[x]=freq.get(x,0)+1
        # ans=0
        # maxval=0
        # for x in freq:
        #     if freq[x] > maxval:
        #         maxval = freq[x]
        #         ans = x
        # return ans


        winner = -1
        count = 0

        for x in nums:
            if count == 0:
                count = 1
                winner = x
            elif x == winner:
                count += 1
            else:
                count -= 1

        return winner