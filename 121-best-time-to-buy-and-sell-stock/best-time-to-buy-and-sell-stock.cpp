class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans=0;
        int a=nums[0];
        for(int i=1;i<nums.size();i++){
            a=min(nums[i],a);
            ans=max(ans,nums[i]-a);
        }
        return ans;
    }
};