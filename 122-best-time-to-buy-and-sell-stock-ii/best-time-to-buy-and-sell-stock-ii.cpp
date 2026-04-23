class Solution {
public:
    // int recur(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp) {
    //     if (idx >= prices.size())
    //         return 0;
    //     if (dp[idx][buy] != -1)
    //         return dp[idx][buy];
    //     int ans = 0;
    //     if (buy == 1) {
    //         ans = max(ans, -prices[idx] + recur(idx + 1, 0, prices, dp));
    //     } else { // buy = 0
    //         ans = max(ans, prices[idx] + recur(idx + 1, 1, prices, dp));
    //     }
    //     // hold
    //     ans = max(ans, 0 + recur(idx + 1, buy, prices, dp));
    //     return dp[idx][buy] = ans;
    // }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1 , vector<int>(2, 0));
        // return recur(0 , 1, prices , dp);// buy = 1 , sell  = 0 ;

        for (int idx = prices.size() - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                int ans = 0;
                if (buy == 1) {
                    ans =
                        max(ans, -prices[idx] + dp[idx+1][0]);
                } else { // buy = 0
                    ans = max(ans, prices[idx] + dp[idx+1][1]);
                }
                // hold
                ans = max(ans, 0 + dp[idx+1][buy]);
               dp[idx][buy] = ans;
            }
        }

        return dp[0][1];
    }
};