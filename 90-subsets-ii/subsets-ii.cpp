class Solution {
public:

    void recur(int index,vector<int>&nums,vector<int>temp,set<vector<int>>&ans_set){
        if(index>=nums.size()){
            ans_set.insert(temp);
            return;
        }
        temp.push_back(nums[index]);
        recur(index+1,nums,temp,ans_set);
        temp.pop_back();
        recur(index+1,nums,temp,ans_set);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>ans_set;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        recur(0,nums,temp,ans_set);
        vector<vector<int>>ans;
        for(auto i:ans_set){
            ans.push_back(i);
        }
        return ans;
    }
};