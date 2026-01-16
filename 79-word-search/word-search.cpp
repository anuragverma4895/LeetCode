class Solution {
public:

    // bool dfs(vector<vector<char>>&board,string &word, int i,int j, int index,vector<vector<int>>&vis){
    //     if(index==word.size()) return true;
    //     int n=board.size();
    //     int m=board[0].size();
    //     if(i<0 || j<0||i>=n || j>=m) return false;
    //     if(vis[i][j] || board[i][j] != word[index]) return false;
    //     vis[i][j]=1;
    //     bool ok=dfs(board, word, i+1, j, index+1, vis) ||
    //         dfs(board, word, i-1, j, index+1, vis) ||
    //         dfs(board, word, i, j+1, index+1, vis) ||
    //         dfs(board, word, i, j-1, index+1, vis);
    //     vis[i][j]=0;
    //     return ok;
    // }

    bool dfs(vector<vector<char>>&board,string &word, int i,int j, int index,vector<vector<int>>&vis){
        if(index==word.size()) return true;
        int n=board.size();
        int m=board[0].size();
        if(i<0 || j<0||i>=n || j>=m) return false;
        if(vis[i][j] || board[i][j] != word[index]) return false;
        vis[i][j]=1;
        int cx[]={1,-1,0,0};
        int cy[]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int ni=i+cx[k];
            int nj=j+cy[k];
            if(dfs(board, word,ni,nj,index+1, vis)){
                vis[i][j]=0;
                return true;
            }
        }
        vis[i][j]=0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(board, word, i,j,0,vis)) return true;
            }
        }
        return false;
    }
};