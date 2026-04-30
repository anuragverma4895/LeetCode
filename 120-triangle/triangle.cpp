class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < t[i].size(); j++) {

                if (j == 0) {
                    t[i][j] += t[i - 1][j];
                }
                else if (j == t[i].size() - 1) {
                    t[i][j] += t[i - 1][j - 1];
                }
                else {
                    int a = t[i - 1][j];
                    int b = t[i - 1][j - 1];
                    t[i][j] += min(a, b);
                }
            }
        }

        int ans = INT_MAX;
        int m = t[n - 1].size();

        for (int i = 0; i < m; i++) {
            ans = min(ans, t[n - 1][i]);
        }
        return ans;
    }
};