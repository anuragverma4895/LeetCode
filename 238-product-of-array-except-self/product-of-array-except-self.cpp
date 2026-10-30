class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        int pre=1;
        for(int i=0;i<nums.size();i++){
            ans.push_back(pre);
            pre*=nums[i];
        }
        int suff=1; 
        for(int i=n-1;i>=0;i--){
            ans[i]*=suff;
            suff*=nums[i];
        }
        return ans;
    }
};