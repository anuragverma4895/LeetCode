class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return -1;
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        int ans = INT_MAX;

        for (int i = 0; i < n - 2; i++) {
            if (arr[i].first == arr[i + 1].first &&
                arr[i + 1].first == arr[i + 2].first) {
                ans=min(ans,((abs(arr[i].second-arr[i+1].second))+(abs(arr[i+1].second-arr[i+2].second))+(abs(arr[i+2].second-arr[i].second))));
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};