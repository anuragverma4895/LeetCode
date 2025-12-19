class Solution {
public:
    void recur(int index, vector<int>& nums, int target, vector<int>& temp, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (index >= nums.size() || target < 0) return;

        temp.push_back(nums[index]);
        recur(index + 1, nums, target - nums[index], temp, ans);
        temp.pop_back();

        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) index++;
        recur(index + 1, nums, target, temp, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        recur(0, nums, target, temp, ans);
        return ans;
    }
};
