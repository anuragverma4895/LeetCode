// class Solution {
// public:
    // int ts(vector<int>&nums){
    //     int sum=0;
    //     for(int i=0;i<nums.size();i++){
    //         sum+= nums[i]*i;
    //     }
    //     return sum; 
    // }
    // int maxRotateFunction(vector<int>& nums) {
    //     int ans=INT_MIN;
    //     int n=nums.size();
    //     if(n==1) return 0;
    //     for(int i=0;i<n;i++){
    //         ans=max(ans,ts(nums));
    //         reverse(nums.begin(), nums.end());
    //         reverse(nums.begin(), nums.begin() + 1);
    //         reverse(nums.begin() + 1, nums.end());
    //     }
    //     return ans;
    // }
// };


class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0, f = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
            f += 1LL * nums[i] * i;
        }

        long long ans = f;

        for(int i = n - 1; i > 0; i--){
            f = f + sum - 1LL * n * nums[i];
            ans = max(ans, f);
        }

        return ans;
    }
};