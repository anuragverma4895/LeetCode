// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         vector<int>ans;
//         for(int i=0;i<nums.size();i++){
//             int temp=0;
//             for(int j=0;j<nums.size();j++){
//                 if(nums[i]>nums[j]){
//                     temp++;
//                 }
//             }
//             ans.push_back(temp);
//         }
//         return ans;
//     }
// };



class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> mp;

        for (int i = 0; i < sorted.size(); i++) {
            if (mp.find(sorted[i]) == mp.end()) {
                mp[sorted[i]] = i;
            }
        }

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(mp[nums[i]]);
        }

        return ans;
    }
};