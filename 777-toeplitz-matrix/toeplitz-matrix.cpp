class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m-1;j++){
                if(nums[i][j]!=nums[i+1][j+1]){
                    return false;
                }
            }
        }
        return true;
    }
};