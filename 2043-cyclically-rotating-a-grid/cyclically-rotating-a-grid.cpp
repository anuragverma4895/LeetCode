class Solution {
public:
    vector<int> getring(vector<vector<int>>& grid,int top,int left,int bottom,int right){
        vector<int> v;

        for(int j=left;j<=right;j++) v.push_back(grid[top][j]);

        for(int i=top+1;i<=bottom-1;i++) v.push_back(grid[i][right]);

        for(int j=right;j>=left;j--) v.push_back(grid[bottom][j]);

        for(int i=bottom-1;i>=top+1;i--) v.push_back(grid[i][left]);

        return v;
    }

    void fillring(vector<vector<int>>& grid,vector<int>& v,int top,int left,int bottom,int right){
        int k=0;

        for(int j=left;j<=right;j++) grid[top][j]=v[k++];

        for(int i=top+1;i<=bottom-1;i++) grid[i][right]=v[k++];

        for(int j=right;j>=left;j--) grid[bottom][j]=v[k++];

        for(int i=bottom-1;i>=top+1;i--) grid[i][left]=v[k++];
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();

        int layers=min(m,n)/2;

        for(int l=0;l<layers;l++){
            int top=l,left=l;
            int bottom=m-l-1,right=n-l-1;

            vector<int> v=getring(grid,top,left,bottom,right);

            int sz=v.size();

            int rot=k%sz;

            rotate(v.begin(),v.begin()+rot,v.end());

            fillring(grid,v,top,left,bottom,right);
        }

        return grid;
    }
};