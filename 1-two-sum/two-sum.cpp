// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n=nums.size();
//         for(int i=0;i<n-1;i++){
//             for(int j=i+1;j<n;j++){
//                 if((nums[i] + nums[j])==target){
//                     return {i,j};
//                 }
//             }
//         }
//         return {-1,-1};
//     }
// };
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>>ans;
        for(int i=0;i<n;i++){
            ans.push_back({nums[i],i});
        }
        sort(ans.begin(),ans.end());
        int low=0,high=n-1;
        while(low<high){
            if((ans[low].first+ans[high].first)==target) return {ans[low].second,ans[high].second};
            else if((ans[low].first+ans[high].first)>target){
                high--;
            }else{
                low++;
            }
        }
        return {-1,-1};
    }
};