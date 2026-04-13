class Solution {
public:
    int recur(int idx,vector<int>&nums,vector<int>&dp){
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        // take
        int a=nums[idx]+recur(idx+2,nums,dp);
        // not take
        int b=0+recur(idx+1,nums,dp);
        return dp[idx]=max(a,b);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return recur(0,nums,dp);
    }
};