class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int ans=1;
        int temp=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]){
                continue;
            }else if(nums[i-1]+1==nums[i]){
                temp++;
            }
            else{
                temp=1;
            }
            ans=max(ans,temp);
        }
        // ans=max(ans,temp);
        return ans;
    }
};