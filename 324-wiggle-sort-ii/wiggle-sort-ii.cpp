class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto mid = nums.begin() + n / 2;
        nth_element(nums.begin(), mid, nums.end());
        int median = *mid;

        auto idx = [&](int i) { return (2 * i + 1) % (n | 1); };

        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (nums[idx(j)] > median) {
                swap(nums[idx(i)], nums[idx(j)]);
                i++; j++;
            } else if (nums[idx(j)] < median) {
                swap(nums[idx(j)], nums[idx(k)]);
                k--;
            } else {
                j++;
            }
        }
    }
};
