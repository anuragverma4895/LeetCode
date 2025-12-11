class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        vector<vector<int>>ans;
        ans.push_back(v[0]);
        for(int i=1;i<v.size();i++){
            if(v[i][0]<=ans.back()[1]){
                ans.back()[1]=max(v[i][1],ans.back()[1]);
            }else{
                ans.push_back(v[i]);
            }
        }
        return ans;
    }
};