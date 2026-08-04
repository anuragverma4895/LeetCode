class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int a=nums[0];
        for(int i=1;i<nums.size();){
            if(a+1!=nums[i]){
                ans.push_back(a+1);
                a=a+1;
            }else{
                a=nums[i];
                i++;
            }
        }
        return ans;
    }
};