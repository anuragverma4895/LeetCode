class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        int n=a.size();
        int m=a[0].size();
        vector<int>temp=a[0];
        for(int i=1;i<n;i++){
            vector<int>curr;
            for(int j=0;j<m;j++){
                for(int it=0;it<temp.size();it++){
                    curr.push_back(temp[it]+a[i][j]);
                }
            }
            sort(curr.begin(),curr.end());
            temp.clear();
            int max_size=min(k+1,(int)curr.size());
            for(int j=0;j<max_size;j++){
                temp.push_back(curr[j]);
            }
        }
        return temp[k-1];
    }
};