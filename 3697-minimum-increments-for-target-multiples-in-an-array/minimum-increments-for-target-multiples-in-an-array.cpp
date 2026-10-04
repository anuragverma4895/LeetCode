class Solution {
public:
    long long minimumIncrements(vector<int>& nums, vector<int>& target) {
        int n = target.size();
        int m = 1 << n;
        vector<long long> dp(m, 1e18);
        dp[0] = 0;
        for (int x : nums) {
            vector<long long> ndp = dp;
            for (int mask = 0; mask < m; mask++) {
                if (dp[mask] == 1e18) {
                    continue;
                }
                for (int sub = 1; sub < m; sub++) {
                    long long lcm = 1;
                    for (int j = 0; j < n; j++) {
                        if (sub & (1 << j)) {
                            lcm = lcm / gcd(lcm, (long long)target[j]) * target[j];

                            if (lcm > 1e18) {
                                break;
                            }
                        }
                    }
                    if (lcm == 0 and lcm > 1e18) {
                        continue;
                    }
                    long long next = ((x + lcm - 1) / lcm) * lcm;
                    long long cost = next - x;
                    int newMask = mask | sub;
                    ndp[newMask] = min(ndp[newMask], dp[mask] + cost);
                }
            }
            dp = ndp;
        }
        return dp[m - 1];
    }
};