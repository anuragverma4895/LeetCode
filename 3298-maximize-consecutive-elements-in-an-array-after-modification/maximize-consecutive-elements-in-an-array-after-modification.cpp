
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;
        int ans = 0;

        for (int x : nums) {
            int takePlus = dp[x] + 1;
            int takeSame = dp[x - 1] + 1;

            dp[x + 1] = max(dp[x + 1], takePlus);
            dp[x] = max(dp[x], takeSame);

            ans = max({ans, dp[x], dp[x + 1]});
        }

        return ans;
    }
};
