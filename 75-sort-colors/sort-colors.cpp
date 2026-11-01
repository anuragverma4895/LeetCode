// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int zero=0;
//         int one=0;
//         int two=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==0) zero++;
//             if(nums[i]==1) one++;
//             if(nums[i]==2) two++;
//         }
//         for(int i=0;i<nums.size();i++){
//             if(i<zero) nums[i]=0;
//             else if(i<zero+one) nums[i]=1;
//             else nums[i]=2;
//         }
//     }
// };



class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }else if(nums[mid]==1) mid++;
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};