class Solution {
public:
    bool check(vector<int>& v, int k) {
        vector<vector<int>> dp(v.size() + 1, vector<int>(k + 10, 0));
        int n = v.size();
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int target = 0; target <= k; target++) {
                if (target == 0) {
                    dp[idx][0] = 1;
                    continue;
                }
                bool take = false;
                if (target >= v[idx])
                    take =
                        dp[idx + 1]
                          [target - v[idx]]; // recur(idx + 1, target - v[idx],
                                             // v, dp); target += v[idx];

                // not take
                bool not_take =
                    dp[idx + 1][target]; // recur(idx + 1, target, v, dp);

                dp[idx][target] = (take || not_take) ? 1 : 0;
            }
        }

        return dp[0][k];
    }
    bool canPartition(vector<int>& nums) {
        int totl_sum = 0;
        for (auto x : nums)
            totl_sum += x;
        if(totl_sum%2 == 1) return false;
        return check(nums, totl_sum / 2);
    }
};