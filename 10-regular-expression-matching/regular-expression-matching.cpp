class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        // dp[i][j] = whether s[i:] matches p[j:]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return matchHelper(s, p, 0, 0, dp);
    }
    
private:
    bool matchHelper(const string &s, const string &p, int i, int j, vector<vector<int>> &dp) {
        if (dp[i][j] != -1) return dp[i][j];
        
        if (j == p.size()) {
            // Pattern exhausted, string must also be exhausted
            return dp[i][j] = (i == s.size());
        }
        
        // Check if current characters match
        bool firstMatch = (i < s.size() && (p[j] == s[i] || p[j] == '.'));
        
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Two options:
            // 1. '*' counts as zero occurrence: skip p[j] and p[j+1]
            // 2. If firstMatch, '*' counts as one or more occurrence: move i forward
            dp[i][j] = matchHelper(s, p, i, j + 2, dp) || (firstMatch && matchHelper(s, p, i + 1, j, dp));
            return dp[i][j];
        } else {
            // Next char is not '*', so must match current char and move both pointers
            dp[i][j] = firstMatch && matchHelper(s, p, i + 1, j + 1, dp);
            return dp[i][j];
        }
    }
};