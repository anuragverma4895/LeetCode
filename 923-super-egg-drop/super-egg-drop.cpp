class Solution {
public:

    int recur(int k , int n,vector<vector<int>> & dp){
        if(k == 1) return n;
        if(n == 0 or n == 1) return n;
        if(dp[k][n] != -1) return dp[k][n];
        int ans = 1e7;
        int l =1 , h = n;
        // for(int break_i = 1 ; break_i <=n; break_i++){
        //     int moves = 
        // }
        while(l <=h){
            int mid = (l +h)/2;
            int break_y = recur(k-1 ,mid - 1,dp);
            int break_n = recur(k, n - mid,dp);
            int moves = 1 + max(break_y, break_n);

            if(break_y < break_n){
                l = mid + 1;
            }else{
                h = mid - 1;
            }
            ans = min(ans, moves);
        }

        return dp[k][n] = ans;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        return recur(k, n,dp);
    }
};