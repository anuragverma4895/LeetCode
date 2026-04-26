class Solution {
public:
    int n,m;
    bool dfs(int i,int j,int pi,int pj,vector<vector<char>>& g,vector<vector<int>>& vis){
        vis[i][j]=1;
        int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        for(int k=0;k<4;k++){
            int ni=i+d[k][0], nj=j+d[k][1];
            if(ni>=0 && nj>=0 && ni<n && nj<m && g[ni][nj]==g[i][j]){
                if(!vis[ni][nj]){
                    if(dfs(ni,nj,i,j,g,vis)) return true;
                }
                else if(ni!=pi || nj!=pj) return true;
            }
        }
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1,grid,vis)) return true;
                }
            }
        }
        return false;
    }
};