class Solution:
    def intersection(self, nums1: list[int], nums2: list[int]) -> list[int]:
        lst=[]
        nums1.sort()
        nums2.sort()
        n=len(nums1)
        m=len(nums2)
        i=0
        j=0
        while i<n and j<m:
            if nums1[i]==nums2[j] and (not lst or lst[-1]!=nums1[i]):
                lst.append(nums1[i])
            elif nums1[i]>nums2[j]:
                j+=1
            else:
                i+=1
        return lst

