class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>ans_st;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int k=0;k<n;k++){
            if(k!=0 && nums[k]==nums[k-1]){
                continue;
            }
            int t=-nums[k];
            int lo=k+1;
            int hi=n-1;
            while(lo<hi){
                int sum=nums[lo]+nums[hi];
                if(sum==t){
                    ans.push_back({-t,nums[lo],nums[hi]});
                    lo++;
                    hi--;
                    while(lo<hi && nums[lo]==nums[lo-1]){
                        lo++;
                    }
                    while(lo<hi && nums[hi]==nums[hi+1]){
                        hi--;
                    }
                }else if(sum<t){
                    lo++;
                }else{
                    hi--;
                }
            }
        }
        return ans;
    }
};