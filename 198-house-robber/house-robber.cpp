class Solution {
public:

    // TC:O(n)  SC:O(n)

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

    int rob(vector<int>& nums){
        int n=nums.size();
        vector<int>dp(n+1,-1);
        for(int idx=n-1;idx>=0;idx--){
            int ans1=nums[idx];
            if(idx+2<n){
                ans1+=dp[idx+2];
            }
            int ans2=0;
            if(idx+1<n){
                ans2+=dp[idx+1];
            }
            dp[idx]=max(ans1,ans2);
        }
        return dp[0];
    }



    // // memoization start from last
    // int recur(int n,vector<int>&nums,vector<int>&dp){
    //     if(n<0) return 0;
    //     if(dp[n]!=-1) return dp[n];
    //     int take=nums[n]+recur(n-2,nums,dp);
    //     int nottake=0+recur(n-1,nums,dp);
    //     return dp[n]=max(take,nottake);
    // }
    // int rob(vector<int>& nums){
    //     int n=nums.size();
    //     vector<int>dp(n+1,-1);
    //     return recur(n-1,nums,dp);
    // }

    // // tabulation
    // int rob(vector<int>& nums){
    //     int n=nums.size();
    //     vector<int>dp(n+1,-1);
    //     for(int i=0;i<n;i++){
    //         int take=nums[i];
    //         if(i-2>=0)
    //             take+=dp[i-2];
    //         int nottake=0;
    //         if(i-1>=0) nottake+=dp[i-1];
    //         dp[i]=max(take,nottake);

    //     }
    //     return dp[n-1];
    // }


};