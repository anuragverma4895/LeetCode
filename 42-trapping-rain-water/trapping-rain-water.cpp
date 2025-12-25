class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size();
        vector<int>pref_max(n,0),suff_max(n,0);
        pref_max[0]=v[0];
        for(int i=1;i<n;i++){
            pref_max[i]=max(v[i],pref_max[i-1]);
        }
        suff_max[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--){
            suff_max[i] = max(v[i],suff_max[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int left=pref_max[i];
            int right=suff_max[i];
            ans+=min(right,left)-v[i];
        }
        return ans;
    }
};