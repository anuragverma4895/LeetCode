class Solution {
public:

    int recur(int idx, int prev,vector<int>&nums,vector<vector<int>> & dp){

        if(idx >= nums.size()) return 0;
        // if(dp[idx].find(prev) != dp[idx].end()) return dp[idx][prev];
        if(dp[idx][prev + 1] != -1) return dp[idx][prev+ 1];
        // take 
        int take = 0;
        if( prev == -1 ||   nums[idx] > nums[prev]){
            take = 1 + recur(idx+1 , idx, nums,dp);
        }

        int not_take = 0 + recur(idx +1 , prev, nums,dp);

        return  dp[idx][prev + 1] =  max(take,not_take);

    }

    int lengthOfLIS(vector<int>& nums) {
        // map<int,map<int,int>> dp;
        vector<vector<int>> dp(nums.size() + 10, vector<int> (nums.size() + 10, -1));
        return recur(0 , -1 ,nums,dp);
    }
};