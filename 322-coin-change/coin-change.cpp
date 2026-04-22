class Solution {
public:
    int dp[13][10000 + 10];
    long long recur(int idx, int sum, vector<int>& coins) {

        // if (sum < 0) {
        //     return 1e9;
        // }
        if (sum == 0) {
            return 0;
        }
        if (idx >= coins.size()) {
            return 1e9;
        }

        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        // not take
        // take 1
        // take 2
        // take 3 ..4.5..55. ?
        // long long ans = 1e9;
        // long long cnt = 0;

        // while (sum - coins[idx] * cnt >= 0) {
        //     ans = min(ans,
        //               cnt + recur(idx + 1, sum - coins[idx] * cnt, coins,
        //               dp));
        //     cnt++;
        // }
        // if (ans >= 1e9)
        //     return 1e9;
        // return dp[idx][sum] = ans;

        int take = 1e9;
        if (sum >= coins[idx]) {
            take = 1 + recur(idx, sum - coins[idx], coins);
        }
        int not_take = 0 + recur(idx + 1, sum, coins);
        int ans = min(take, not_take);
        if(ans >= 1e9) return  dp[idx][sum] = 1e9; 
        return dp[idx][sum] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {

        memset(dp,-1, sizeof(dp));

        // vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        int ans = recur(0, amount, coins);

        if (ans >= 1e9)
            return -1;
        return ans;
    }
};