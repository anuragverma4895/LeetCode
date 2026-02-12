class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int sz=nums.size();
        vector<int>ans;
        int j=0,k=n;
        while(j<n){
            ans.push_back(nums[j++]);
            ans.push_back(nums[k++]);
        }
        return ans;
    }
};