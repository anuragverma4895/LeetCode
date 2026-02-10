class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        vector<int> t = nums;
        int n = (int)t.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            unordered_set<int> evenset, oddset;
            for (int j = i; j < n; ++j) {
                int val = t[j];
                if ((val & 1) == 0) {
                    evenset.insert(val);
                } else {
                    oddset.insert(val);
                }
                if (evenset.size() == oddset.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};