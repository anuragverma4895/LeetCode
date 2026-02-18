class Solution {
public:
    // grid pattern problem
    void dfs(vector<vector<int>>&grid, int cx, int cy, vector<vector<int>>&vis){
        vis[cx][cy]=1;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1 && vis[nx][ny]==0){
                dfs(grid,nx,ny,vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0) or (j==0) or (i==n-1) or (j==m-1)){
                    if(vis[i][j]==0 and grid[i][j]==1){
                        dfs(grid,i,j,vis);
                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
};