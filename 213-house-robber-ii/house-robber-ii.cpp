class Solution {
public:
    int recur(int idx, int nc, vector<int>&nums, vector<int>&dp){
        if(idx>=nc) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take=nums[idx]+recur(idx+2,nc,nums,dp);
        int nottake=0+recur(idx+1,nc,nums,dp);
        return dp[idx]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        return max(recur(0,n-1,nums,dp1),recur(1,n,nums,dp2));

    }
};