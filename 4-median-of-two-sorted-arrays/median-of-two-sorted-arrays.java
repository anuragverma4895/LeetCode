class Solution {
    
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;
        int i =0;
        int j =0;
        int curr =0;
        int prev = 0;
        int mid = (n+m)/2;
        for(int k = 0;k<=mid;k++){
            prev = curr;
            if(i<n && j<m){
                if(nums1[i] <= nums2[j]){
                    curr = nums1[i];
                    i++;
                }
                else{
                    curr = nums2[j];
                    j++;
                }
            }
            else if(i< n){
                curr = nums1[i];
                i++;
            }
            else{
                curr = nums2[j];
                j++;
            }
        }
        if((n+m)%2 ==1){
            return curr;
        }
        return (double)((curr+prev)/2.0);
        
    }
}