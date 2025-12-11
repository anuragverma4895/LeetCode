class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        vector<int>ans;
        int n=v.size();
        int m=v[0].size();
        int top=0;
        int bottom=n-1;
        int left=0;
        int right=m-1;
        while(left<=right && top<=bottom){
            for(int j=left;j<=right;j++){
                ans.push_back(v[top][j]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ans.push_back(v[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int j=right;j>=left;j--){
                    ans.push_back(v[bottom][j]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i = bottom;i>=top;i--){
                    ans.push_back(v[i][left]);
                }
                left++;
            }
            
        }
        return ans;
    }
};