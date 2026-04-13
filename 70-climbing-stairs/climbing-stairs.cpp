class Solution {
public:

    int recur(int n,vector<int>&dp){
        if(n==0 or n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=recur(n-1,dp)+recur(n-2,dp);
    }
    int climbStairs(int n) {

        vector<int>dp(n+1,-1);
        return recur(n,dp);
        // if(n<=2) return n;
        // int a=1,b=2,result;
        // for(int i=3;i<=n;i++){
        //     result=a+b;
        //     a=b;
        //     b=result;
        // }
        // return b;

    }
};