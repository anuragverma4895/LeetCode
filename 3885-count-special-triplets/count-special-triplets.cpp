class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long mod = 1e9 + 7;
        unordered_map<long long,long long> left, right;

        for (auto &x : nums) right[x]++;

        long long ans = 0;

        for (int j = 0; j < nums.size(); j++) {
            long long x = nums[j];
            right[x]--;

            long long need = x * 2;
            ans = (ans + left[need] * right[need]) % mod;

            left[x]++;
        }
        return ans;
    }
};
