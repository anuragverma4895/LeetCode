class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<bool> fixed(n, false);
        int ans = 0;
        for (int c = 0; c < m; c++) {
            bool bad = false;
            for (int i = 1; i < n; i++) {
                if (!fixed[i] && strs[i-1][c] > strs[i][c]) {
                    bad = true;
                    break;
                }
            }
            if (bad) {
                ans++;
                continue;
            }
            for (int i = 1; i < n; i++) {
                if (!fixed[i] && strs[i-1][c] < strs[i][c]) {
                    fixed[i] = true;
                }
            }
        }
        return ans;
    }
};
