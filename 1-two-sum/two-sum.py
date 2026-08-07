class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # n=len(nums)
        # for i in range(n):
        #     for j in range(i+1,n):
        #         if nums[i]+nums[j]==target:
        #             return [i,j]
        # return [-1,-1]

        n=len(nums)
        v=[]
        for i in range(n):
            v.append((nums[i],i))
        v.sort()
        low=0
        high=n-1
        while low<high:
            sum=v[low][0]+v[high][0]
            if target==sum:
                return [v[low][1],v[high][1]]
            elif sum<target:
                low+=1
            else:
                high-=1
        return [-1,-1]