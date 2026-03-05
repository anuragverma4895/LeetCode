// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         if(nums[n-1] <= 0) return 1;
//         int last = 0;
//         for(int i = 0; i < n; i++){
//             if(nums[i] <= 0) continue;
//             if(nums[i] > last + 1) return last + 1;
//             last = max(last, nums[i]);
//         }
//         return last + 1;
//     }
// };

// optimal code
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!=nums[i]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};