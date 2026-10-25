# class Solution:
#     def isAnagram(self, s: str, t: str) -> bool:
#         a=sorted(s)
#         b=sorted(t)
#         n=len(a)
#         m=len(b)
#         if m!=n:
#             return False
#         for i in range(m):
#             if a[i]!=b[i]:
#                 return False
#         return True
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        a=sorted(s)
        b=sorted(t)
        return a==b