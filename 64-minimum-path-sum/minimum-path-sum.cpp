class Solution {
public:
    int recur(int i, int j, int n,int m ,vector<vector<int>>&dp, vector<vector<int>>&grid){
        // if(i<0 or j<0 or i>=n-1 or j>=m-1) return 0;
        if(i>=n or j>=m) return INT_MAX;
        if (i == n - 1 && j == m - 1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int left=recur(i+1,j,n,m,dp,grid);
        int right=recur(i,j+1,n,m,dp,grid);
        return dp[i][j]=grid[i][j]+min(left,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return recur(0,0,n,m,dp,grid);
    }
};