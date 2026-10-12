class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int a;
        int b;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            a=nums[i];
            b=nums[i];
            for(int j=i;j<nums.size();j++){
                a=max(a,nums[j]);
                b=min(nums[j],b);
                ans+=a-b;
            }
        }
        return ans;
    }
};