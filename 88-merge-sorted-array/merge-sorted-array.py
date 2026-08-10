class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        # arr=[]
        # for i in range(m):
        #     arr.append(nums1[i])
        # for j in range(n):
        #     arr.append(nums2[j])
        # arr.sort()
        # nums1[:]=arr

        # j=m
        # for i in range(n):
        #     nums1[j]=nums2[i]
        #     j+=1


        k=len(nums1)-1
        i=m-1
        j=n-1
        while j >= 0:
            if i >= 0 and nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1

            k -= 1


        