class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>freq(nums.size()+1);
        vector<int>ans(2);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i]>1) ans[0]=i;
            if(freq[i]==0) ans[1]=i;
        }
        return ans;
    }
};