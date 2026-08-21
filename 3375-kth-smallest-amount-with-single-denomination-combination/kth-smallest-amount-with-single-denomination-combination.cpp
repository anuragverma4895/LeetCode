class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto cnt = [&](long long x) {
            long long ans = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                long long l = 1;
                int bits = 0;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;
                        l = l / gcd(l, (long long)coins[i]) * coins[i];
                        if (l > x) break;
                    }
                }

                if (l <= x)
                    ans += (bits & 1) ? x / l : -x / l;
            }

            return ans;
        };

        long long l = 1;
        long long r = 1LL * *min_element(coins.begin(), coins.end()) * k;

        while (l < r) {
            long long mid = l + (r - l) / 2;

            if (cnt(mid) >= k)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};