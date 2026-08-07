class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        n=len(nums)
        ans=[]
        total=nums[0]
        ans.append(total)
        for i in range(1,n):
            total+=nums[i]
            ans.append(total)
        return ans