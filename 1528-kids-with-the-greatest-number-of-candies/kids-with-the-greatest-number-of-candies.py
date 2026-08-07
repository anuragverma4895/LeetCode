class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        max1=max(candies)
        ans=[]
        for i in range(len(candies)):
            if max1<=(candies[i]+extraCandies):
                ans.append(True)
            else:
                ans.append(False)
        return ans
