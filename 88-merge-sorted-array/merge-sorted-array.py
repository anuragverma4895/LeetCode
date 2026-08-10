class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        arr=[]
        for i in range(m):
            arr.append(nums1[i])
        for j in range(n):
            arr.append(nums2[j])
        arr.sort()
        nums1[:]=arr
        