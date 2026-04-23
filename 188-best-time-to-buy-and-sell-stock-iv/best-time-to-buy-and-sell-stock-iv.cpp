class Solution {
public:
    int recur(int idx, int buy, int trans, vector<int>& prices,
              vector<vector<vector<int>>>& dp) {

        if (idx >= prices.size())
            return 0;
        if (trans <= 0)
            return 0;

        if (dp[idx][buy][trans] != -1)
            return dp[idx][buy][trans];
        // do
        int ans = 0;
        if (buy == 1) {
            ans = max(ans, -prices[idx] + recur(idx + 1, 0, trans, prices, dp));
        } else {
            ans = max(ans,
                      prices[idx] + recur(idx + 1, 1, trans - 1, prices, dp));
        }
        // skip
        ans = max(ans, 0 + recur(idx + 1, buy, trans, prices, dp));

        return dp[idx][buy][trans] = ans;
    }

    int maxProfit(int k, vector<int>& prices) {

        vector<vector<vector<int>>> dp(
            prices.size() + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return recur(0, 1, k, prices, dp);
    }
};