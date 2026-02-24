class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        if(v.size()<2) return 0;
        int count=0;
        vector<vector<int>>ans;
        ans.push_back(v[0]);
        for(int i=1;i<v.size();i++){
            if(ans.back()[1] > v[i][0]){
                ans.back()[0]=min(ans.back()[0],v[i][0]);
                ans.back()[1]=min(ans.back()[1],v[i][1]);
                count++;
            }
            else{
                ans.push_back(v[i]);
            }
        }
        return count;
    }
};