class Solution {
public:
    int dp[1001][1001];
    // int recur(int i, int j , string &s1, string &s2){

    //     if(i >= s1.length() or j >= s2.length()){
    //         return 0;
    //     }
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s1[i] == s2[j]){
    //         return dp[i][j]=  1 + recur(i+1 , j+1 , s1,s2);
    //     }

    //     return dp[i][j]=  max(recur(i+1, j, s1,s2), recur(i, j+1, s1,s2));
    // }
    int longestCommonSubsequence(string s1, string s2) {
        // int dp[s1.length() + 1][s2.length() + 1];
        memset(dp,0,sizeof(dp));

        for(int i = s1.size() - 1; i>=0 ; i--){
            for(int j = s2.size() -1 ; j>=0 ; j--){
                if(s1[i]== s2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return dp[0][0];

        // return recur(0, 0, s1,s2);
    }
};