class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map<int,int>mp;
        // for(int i=0;i<nums.size();i++){
        //     int a=nums[i];
        //     int b=target-a;
        //     if(mp.find(b)!=mp.end()){
        //         return{i,mp[b]};
        //     }
        //     mp[a]=i;
        // }
        // return {};

        vector<pair<int,int>>v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int lo=0,hi=n-1;
        while(lo<hi){
            int sum=v[lo].first+v[hi].first;
            if(sum==target){
                return {v[lo].second,v[hi].second};
            }else if(sum>target){
                hi--;
            }else{
                lo++;
            }
        }
        return{-1,-1};
    }
};