class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[0];
        // int min1=INT_MAX;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]<min1){
        //         min1=nums[i];
        //     }
        // }
        // return min1;
    }
};