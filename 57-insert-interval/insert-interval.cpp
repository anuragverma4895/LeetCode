class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& newInterval) {
        nums.push_back(newInterval);
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(ans.back()[1]>=nums[i][0]){
                ans.back()[1]=max(nums[i][1],ans.back()[1]);
            }else{
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};