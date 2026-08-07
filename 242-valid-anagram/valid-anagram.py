class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        ans1=sorted(s)
        ans2=sorted(t)
        if len(s)!=len(t):
            return False
        
        for i in range(len(s)):
            if ans1[i]!=ans2[i]:
                return False
        return True