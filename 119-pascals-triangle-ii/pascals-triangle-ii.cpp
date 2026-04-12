class Solution {
public:
    vector<int> getRow(int n) {
        vector<int>ans;
        long long val=1;
        for(int i=0;i<=n;i++){
            ans.push_back(val);
            val=val*(n-i)/(i+1);
        }
        return ans;
    }
};