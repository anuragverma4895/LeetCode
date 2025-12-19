class Solution {
public:
    // void backtrack(int i, int target, vector<int>& c, vector<int>& cur,
    //                vector<vector<int>>& res) {
    //     if (target == 0) {
    //         res.push_back(cur);
    //         return;
    //     }
    //     if (i == c.size() || target < 0)
    //         return;
    //     cur.push_back(c[i]);
    //     backtrack(i, target - c[i], c, cur, res);
    //     cur.pop_back();
    //     backtrack(i + 1, target, c, cur, res);
    // }

    // vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //     vector<vector<int>> res;
    //     vector<int> cur;
    //     backtrack(0, target, candidates, cur, res);
    //     return res;

    void recur(int index, vector<int>&nums, int target, vector<int>&temp, vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(index>=nums.size()){
            return;
        }
        for(int times=0;times*nums[index]<=target;times++){
            for(int k=0;k<times;k++){
                temp.push_back(nums[index]);
            }
            recur(index+1,nums,target-nums[index]*times,temp,ans);
            for(int k=0;k<times;k++){
                temp.pop_back();
            }
        }
    }

    vector<vector<int>>combinationSum(vector<int>&nums, int target){
        vector<int>temp;
        vector<vector<int>>ans;
        recur(0,nums,target,temp,ans);
        return ans;
    }
};
