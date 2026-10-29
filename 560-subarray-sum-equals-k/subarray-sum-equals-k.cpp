// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         unordered_map<int,int> mp;
//         mp[0]=1;
//         int sum=0,ans=0;
//         for(int x:nums){
//             sum+=x;
//             if(mp.count(sum-k)) ans+=mp[sum-k];
//             mp[sum]++;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k) ans++;
            if(mp.find(sum-k)!=mp.end()){
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};











