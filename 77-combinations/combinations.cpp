class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>v(n,0);
        for(int i=0;i<k;i++){
            v[i]=1;
        }
        sort(v.begin(),v.end());
        do{
            vector<int>temp;
            for(int i=0;i<n;i++){
                if(v[i]){
                    temp.push_back(i+1);
                }
            }
            ans.push_back(temp);
        }while(next_permutation(v.begin(),v.end()));
        return ans;
    }
};