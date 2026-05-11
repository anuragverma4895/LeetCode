class Solution {
    public int[] separateDigits(int[] nums) {
        StringBuilder sb = new StringBuilder();
        for(int i = 0;i<nums.length;i++){
            sb.append(nums[i]);
        }
        int n = sb.length();
        int[] ans = new int[n];
        for(int i = 0;i<n;i++){
            // int x= sb.charAt(i);
            // ans[i] = x-48;
            ans[i] = sb.charAt(i) - '0';
        }
        return ans;
    }
}