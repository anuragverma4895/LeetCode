class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        ans=0
        n=len(accounts)
        m=len(accounts[0])
        for i in range(n):
            sum=0
            for j in range(m):
                sum+=accounts[i][j]
            ans=max(ans,sum)
        return ans
