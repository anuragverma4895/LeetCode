class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 or grid[n-1][n-1]==1){
            return -1;
        }
        queue<vector<int>>q;    // i,j,dis
        q.push({0,0,1});
        vector<vector<int>>dis(n,vector<int>(n,1e7));
        dis[0][0]=1;
        int dx[]={-1,-1,-1,0,0,1,1,1};
        int dy[]={-1,0,1,-1,1,-1,0,1};
        while(q.size()){
            int cx=q.front()[0];
            int cy=q.front()[1];
            int cd=q.front()[2];
            q.pop();
            if(cx==n-1 && cy==n-1){
                return cd;
            }
            for(int k=0;k<8;k++){
                int nx=cx+dx[k];
                int ny=cy+dy[k];
                int edge_wt=1;
                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0){
                    if(cd+edge_wt<dis[nx][ny]){
                        dis[nx][ny]=cd+edge_wt;
                        q.push({nx,ny,dis[nx][ny]});
                    }
                }

            }
        }
        return dis[n-1][n-1]==1e7 ? -1 : dis[n-1][n-1];
    }
};