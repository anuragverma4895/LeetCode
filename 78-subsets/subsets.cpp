class Solution {
public:
    void recur(int index, vector<int>&nums,vector<int>temp,vector<vector<int>>&ans){
        if(index>=nums.size()){
            ans.push_back(temp);
            return;
        }
        vector<int>temp2=temp;
        temp2.push_back(nums[index]);
        recur(index+1,nums,temp2,ans);
        recur(index+1,nums,temp,ans);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        recur(0,nums,temp,ans);
        return ans;
        
    }
};