class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(nums[n-1] <= 0) return 1;
        int last = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] <= 0) continue;
            if(nums[i] > last + 1) return last + 1;
            last = max(last, nums[i]);
        }

        return last + 1;
    }
};