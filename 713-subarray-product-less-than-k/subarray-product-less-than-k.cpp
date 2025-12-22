class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        long long product = 1;
        int l=0,ans=0;
        for(int i=0;i<nums.size();i++){
            product*=nums[i];
            while(product>=k){
                product/=nums[l];
                l++;
            }
            ans+=i-l+1;
        }
        return ans;
    }
};
