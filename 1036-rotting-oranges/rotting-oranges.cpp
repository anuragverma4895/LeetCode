class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e5));
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2){
                    q.push({i,j,0});
                    dis[i][j]=0;

                }
            }
        }
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(q.size()){
            int cx=q.front()[0];
            int cy=q.front()[1];
            int level=q.front()[2];
            q.pop();
            for(int k=0;k<4;k++){
                int nx=cx+dx[k];
                int ny=cy+dy[k];
                if(nx>=0 && nx<n && ny>=0 && ny<m && dis[nx][ny]==1e5 && mat[nx][ny]==1){
                    dis[nx][ny]=level+1;
                    q.push({nx,ny,level+1});
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    if(dis[i][j]==1e5){
                        return -1;
                    }
                    ans=max(ans,dis[i][j]);
                }
            }
        }
        return ans;
    }
};