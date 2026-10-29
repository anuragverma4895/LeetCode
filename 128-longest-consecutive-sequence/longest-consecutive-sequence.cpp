// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.empty()) return 0;
//         sort(nums.begin(),nums.end());
//         int ans=1;
//         int temp=1;
//         for(int i=1;i<nums.size();i++){
//             if(nums[i-1]==nums[i]){
//                 continue;
//             }else if(nums[i-1]+1==nums[i]){
//                 temp++;
//             }
//             else{
//                 temp=1;
//             }
//             ans=max(ans,temp);
//         }
//         return ans;
//     }
// };



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int ans=0;
        for(int x:st){
            if(x!=INT_MIN && st.find(x-1)!=st.end()){
                continue;
            }
            int temp=1;
            int curr=x;
            while(curr!=INT_MAX && st.find(curr+1)!=st.end() ){
                curr++;
                temp++;
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};