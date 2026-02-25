class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int j = i;
            int bits = __builtin_popcount(nums[i]);
            while (j < n && __builtin_popcount(nums[j]) == bits)
                j++;
            sort(nums.begin() + i, nums.begin() + j);
            i = j;
        }
        for (int i = 1; i < n; i++)
            if (nums[i] < nums[i - 1])
                return false;
        return true;
    }
};