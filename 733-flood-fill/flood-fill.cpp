class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();

        int oc=image[sr][sc];
        if(oc==color) return image;
        queue<vector<int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        while(q.size()){
            int cx=q.front()[0];
            int cy=q.front()[1];
            q.pop();
            for(int k=0;k<4;k++){
                int nx=cx+dx[k];
                int ny=cy+dy[k];
                if(nx>=0 and nx<n and ny>=0 and ny<m and image[nx][ny]==oc){
                    image[nx][ny]=color;
                    q.push({nx,ny});
                }
            }
        }
        return image;
    }
};