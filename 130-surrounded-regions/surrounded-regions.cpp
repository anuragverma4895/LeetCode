class Solution {
public:

    // use this type of dfs when grid is given(important)
    void dfs(vector<vector<char>>&board, int cx, int cy, vector<vector<int>>&vis){
        vis[cx][cy]=1;
        int dx[]={1,-1,0,0}; //checking up down left right
        int dy[]={0,0,-1,1}; //checking up down left right
        int n=board.size();
        int m=board[0].size();
        for(int k=0;k<4;k++){
            int nx=cx+dx[k];
            int ny=cy+dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && board[nx][ny]=='O' && vis[nx][ny]==0){
                dfs(board,nx,ny,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0) or (j==0) or (i==n-1) or (j==m-1)){
                    if(vis[i][j]==0 and board[i][j]=='O'){
                        dfs(board,i,j,vis);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' and vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};