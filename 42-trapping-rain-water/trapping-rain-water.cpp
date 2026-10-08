class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();
        vector<int>pref(n);
        pref[0]=nums[0];
        vector<int>suff(n);
        suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pref[i]=max(nums[i],pref[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=max(suff[i+1],nums[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(pref[i],suff[i])-nums[i];
        }
        return ans;
    }
};