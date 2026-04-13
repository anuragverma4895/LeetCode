class Solution {
public:
    // // memoization start from starting
    // int recur(int idx,vector<int>&nums,vector<int>&dp){
    //     if(idx>=nums.size()) return 0;
    //     if(dp[idx]!=-1) return dp[idx];
    //     // take
    //     int a=nums[idx]+recur(idx+2,nums,dp);
    //     // not take
    //     int b=0+recur(idx+1,nums,dp);
    //     return dp[idx]=max(a,b);
    // }
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int>dp(n+1,-1);
    //     return recur(0,nums,dp);
    // }

    // memoization start from last
    int recur(int n,vector<int>&nums,vector<int>&dp){
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int take=nums[n]+recur(n-2,nums,dp);
        int nottake=0+recur(n-1,nums,dp);
        return dp[n]=max(take,nottake);
    }
    int rob(vector<int>& nums){
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return recur(n-1,nums,dp);
    }



};