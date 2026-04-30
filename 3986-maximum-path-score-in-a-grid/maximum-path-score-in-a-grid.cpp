class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        
        vector dp(n, vector(m, vector<int>(k+1, -1e9)));
        
        dp[0][0][grid[0][0] > 0 ? 1 : 0] = grid[0][0];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int used=0; used<=k; used++){
                    if(dp[i][j][used] < 0) continue;
                    
                    if(i+1<n){
                        int cost = (grid[i+1][j] > 0);
                        if(used + cost <= k){
                            dp[i+1][j][used + cost] = max(
                                dp[i+1][j][used + cost],
                                dp[i][j][used] + grid[i+1][j]
                            );
                        }
                    }
                    
                    if(j+1<m){
                        int cost = (grid[i][j+1] > 0);
                        if(used + cost <= k){
                            dp[i][j+1][used + cost] = max(
                                dp[i][j+1][used + cost],
                                dp[i][j][used] + grid[i][j+1]
                            );
                        }
                    }
                }
            }
        }
        
        int ans = -1;
        for(int used=0; used<=k; used++){
            ans = max(ans, dp[n-1][m-1][used]);
        }
        
        return ans < 0 ? -1 : ans;
    }
};