class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e5));
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({i,j,0});
                    dis[i][j]=0;
                }
            }
        }
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        while(q.size()){
            int cx=q.front()[0];
            int cy=q.front()[1];
            int level=q.front()[2];
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