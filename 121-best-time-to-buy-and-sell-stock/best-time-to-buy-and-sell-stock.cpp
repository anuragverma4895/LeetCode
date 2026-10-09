class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans=0;
        int a=INT_MAX;
        for(int i=0;i<nums.size();i++){
            a=min(nums[i],a);
            ans=max(ans,nums[i]-a);
        }
        return ans;
    }
};