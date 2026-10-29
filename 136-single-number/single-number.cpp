class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // //O(N)
        // int ans=0;
        // for(int i=0;i<nums.size();i++){
        //     ans^=nums[i];
        // }
        // return ans;

        for(int i=0;i<nums.size();i++){
            int count=1;
            for(int j=0;j<nums.size();j++){
                if(nums[i]==nums[j] and i!=j){
                    count++;
                }
            }
            if(count==1) return nums[i];
        }
        return -1;

    }
};