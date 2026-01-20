class Solution {
public:

    // this code is calculating the distance by using bfs beacuse bfs 
    // is always suitable for finding shortest path
    // important
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e5));
        queue<vector<int>>q; // i,j,dist  --> (store)
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    dis[i][j]=0;

                }
            }
        }
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(q.size()){
            int cx=q.front()[0]; // element in q at 0 index
            int cy=q.front()[1]; // element in q at 1 index
            int level=q.front()[2]; // element in q at 2 index
            q.pop();
            for(int k=0;k<4;k++){
                int nx=cx+dx[k];
                int ny=cy+dy[k];
                if(nx>=0 && nx<n && ny>=0 && ny<m && dis[nx][ny]==1e5){
                    dis[nx][ny]=level+1;
                    q.push({nx,ny,level+1});
                }
            }
        }
        return dis;
    }
};