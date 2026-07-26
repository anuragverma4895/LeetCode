class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n<3) return 0;
        int a=nums[n-3]*nums[n-2]*nums[n-1];
        int b=nums[0]*nums[1]*nums[n-1];
        return a>b?a:b;
    }
};