class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mn = 0, mx = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[mn])
                mn = i;
            if (nums[i] > nums[mx])
                mx = i;
        }

        int a = max(mn, mx) + 1;
        int b = n - min(mn, mx);
        int c = min(mn, mx) + 1 + n - max(mn, mx);

        return min({a, b, c});
    }
};