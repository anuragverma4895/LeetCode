class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int sum=0;
        int count=0;
        int j=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            count++;
            if(sum>=target){
                ans=min(ans,count);
            }
            while(sum>target){
                sum-=nums[j++];
                count--;
                if(sum>=target){
                    ans=min(ans,count);
                }
            }
        }
        return ans==INT_MAX?0:ans;
    }
};