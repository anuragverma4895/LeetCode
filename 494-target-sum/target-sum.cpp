class Solution {
public:
    int recur(int idx, int sum, vector<int>& nums,
              map<int, map<int, int>>& dp) {
        if (idx == nums.size()) {
            if (sum == 0) {
                return 1;
            }
            return 0;
        }
        // if(dp[idx][sum] != -1) return dp[idx][sum];
        if (dp[idx].find(sum) != dp[idx].end())
            return dp[idx][sum];
        // add
        int add = recur(idx + 1, sum - nums[idx], nums, dp);
        // sub
        int sub = recur(idx + 1, sum + nums[idx], nums, dp);

        return dp[idx][sum] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // vector<vector<int>> dp(nums.size() + 1, vector<int> (target));
        map<int, map<int, int>> dp;
        return recur(0, target, nums, dp);
    }
};