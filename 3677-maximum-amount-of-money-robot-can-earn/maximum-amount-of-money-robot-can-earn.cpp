class Solution {
public:
    long long maximumAmount(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(m, vector<long long>(3, -1e18)));

        if (g[0][0] >= 0) dp[0][0][0] = g[0][0];
        else {
            dp[0][0][0] = g[0][0];
            dp[0][0][1] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;

                for (int k = 0; k <= 2; k++) {
                    long long val = g[i][j];

                    if (i > 0 && dp[i-1][j][k] != -1e18)
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + val);

                    if (j > 0 && dp[i][j-1][k] != -1e18)
                        dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k] + val);

                    if (val <= 0 && k > 0) {
                        if (i > 0 && dp[i-1][j][k-1] != -1e18)
                            dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1]);

                        if (j > 0 && dp[i][j-1][k-1] != -1e18)
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1]);
                    }
                }
            }
        }

        return max({dp[n-1][m-1][0], dp[n-1][m-1][1], dp[n-1][m-1][2]});
    }
};