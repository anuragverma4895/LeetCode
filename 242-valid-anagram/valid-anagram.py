class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # ans1=sorted(s)
        # ans2=sorted(t)
        # if len(s)!=len(t):
        #     return False
        
        # for i in range(len(s)):
        #     if ans1[i]!=ans2[i]:
        #         return False
        # return True

        # other method
        return Counter(s)==Counter(t)

        # other method
        if len(s)!=len(t):
            return False
        freq={}
        for ch in s:
            freq[ch]=freq.get(ch,0)+1
        for ch in t:
            if ch not in freq:
                return False
            freq[ch]-=1
        
