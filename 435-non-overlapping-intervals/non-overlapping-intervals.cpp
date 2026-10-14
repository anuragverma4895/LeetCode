class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=-1;
        vector<vector<int>>ans;
        ans.push_back(nums[0]);
        for(int i=0;i<nums.size();i++){
            if(ans.back()[1]>nums[i][0]){
                ans.back()[1]=min(nums[i][1],ans.back()[1]);
                count++;
            }else{
                ans.push_back(nums[i]);
            }
        }
        return count;
    }
};