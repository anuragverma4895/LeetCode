class Solution {
public:
    int dp[1001][1001];
    int longestCommonSubsequence(string s1, string s2) {
        // int dp[s1.length() + 1][s2.length() + 1];
        memset(dp, 0, sizeof(dp));

        // for(int i = s1.size() - 1; i>=0 ; i--){
        //     for(int j = s2.size() -1 ; j>=0 ; j--){
        //         if(s1[i]== s2[j]){
        //             dp[i][j] = 1 + dp[i+1][j+1];
        //         }else{
        //             dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        //         }
        //     }
        // }

        for (int i = 0; i < s1.size(); i++) {
            for (int j = 0; j < s2.size(); j++) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = 1;
                    if (i - 1 >= 0 and j - 1 >= 0)
                        dp[i][j] += dp[i - 1][j - 1];
                } else {
                    // dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    int ans = 0;
                    if (i - 1 >= 0) {
                        ans = max(ans, dp[i - 1][j]);
                    }
                    if (j - 1 >= 0) {
                        ans = max(ans, dp[i][j - 1]);
                    }

                    dp[i][j] = ans;
                }
            }
        }

        // return dp[0][0];

        // return recur(0, 0, s1,s2);

        // return recur(s1.size() -1 , s2.size() - 1, s1,s2);

        return dp[s1.size() - 1][s2.size() - 1];
    }
    int longestPalindromeSubseq(string s) {

        string rs = s;
        reverse(rs.begin(), rs.end());

        return longestCommonSubsequence(s, rs);
    }
};