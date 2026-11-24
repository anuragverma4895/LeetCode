class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();

        int l = 0, r = n - 1;

        while (l + 1 < n && nums[l] < nums[l + 1])
            l++;

        while (r > 0 && nums[r - 1] > nums[r])
            r--;

        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long left = 0;
        long long ans = LLONG_MAX;

        for (int i = 0; i < n - 1; i++) {
            left += nums[i];

            if (i <= l && i + 1 >= r) {
                long long right = total - left;
                ans = min(ans, abs(left - right));
            }
        }

        return ans == LLONG_MAX ? -1 : ans;
    }
};