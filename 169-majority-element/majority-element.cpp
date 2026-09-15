// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int winner=-1;
//         int count=0;
//         for(auto x:nums){
//             if(count==0){
//                 count=1;
//                 winner=x;
//             }else if(x==winner){
//                 count++;
//             }else{
//                 count--;
//             }
//         }
//         return winner;
//     }
// };



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans=INT_MIN;
        int temp=INT_MIN;
        for(auto it:mp){
            if(it.second>temp){
                temp=it.second;
                ans=it.first;
            }
        }
        return ans;
    }
};