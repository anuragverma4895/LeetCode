class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # nums1.sort()
        # nums2.sort()
        # ans=[]
        # n=len(nums1)
        # m=len(nums2)
        # i=0
        # j=0
        # while i<n and j<m:
        #     if nums1[i]==nums2[j] and (not ans or ans[-1]!=nums1[i]):
        #         ans.append(nums1[i])
        #         i+=1
        #         j+=1
        #     elif nums1[i]<nums2[j]:
        #         i+=1
        #     else:
        #         j+=1
        # return ans


        
        ans1=set(nums1)
        ans2=set(nums2)
        ans=list(ans1.intersection(ans2))
        return ans