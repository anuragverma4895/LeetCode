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


# class Solution:
#     def isAnagram(self, s: str, t: str) -> bool:
#         a=sorted(s)
#         b=sorted(t)
#         return a==b


# class Solution:
#     def isAnagram(self, s: str, t: str) -> bool:
#         if len(s)!=len(t):
#             return False
#         mp={}
#         for x in s:
#             if x in mp:
#                 mp[x]+=1
#             else:
#                 mp[x]=1
#         for x in t:
#             if x not in mp:
#                 return False
#             else:
#                 mp[x]-=1
#         for x in mp:
#             if mp[x]!=0:
#                 return False
#         return True



from collections import Counter
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s)==Counter(t)