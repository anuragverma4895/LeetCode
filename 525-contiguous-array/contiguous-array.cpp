class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int s = 0, ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                s--;
            else
                s++;

            if (mp.count(s)) {
                ans = max(ans, i - mp[s]);
            } else {
                mp[s] = i;
            }
        }

        return ans;
    }
};