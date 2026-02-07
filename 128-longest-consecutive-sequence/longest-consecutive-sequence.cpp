class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Brute force
        // int n=nums.size();
        // if(n==0) return 0;
        // sort(nums.begin(),nums.end());
        // int count=1;
        // int ans=1;
        // for(int i=1;i<n;i++){
        //     if(nums[i]==nums[i-1]) continue;
        //     if(nums[i-1]+1==nums[i]){
        //         count+=1;
        //         ans=max(ans,count);
        //     }else{
        //         count=1;
        //     }
        // }
        // return ans;

        unordered_set<int>st;
        for(int x:nums){
            st.insert(x);
        }
        int ans=0;
        for(int x:st){
            if(st.find(x-1)==st.end()){
                int cur=x;
                int cnt=1;
                while(st.find(cur+1)!=st.end()){
                    cur++;
                    cnt++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};