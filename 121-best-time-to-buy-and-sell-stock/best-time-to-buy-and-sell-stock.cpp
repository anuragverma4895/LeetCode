class Solution {
public:
    int maxProfit(vector<int>& v) {
        int ans=0;
        int n=v.size();
        int mn=v[0];
        for(int i=1;i<n;i++){
            int profit=v[i]-mn;
            ans=max(ans,profit);
            mn=min(mn,v[i]);
        }
        return ans;
    }
};