class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        const int mod = 1e9 + 7;
        for(auto &v : q){
            int l = v[0], r = v[1], k = v[2], val = v[3];
            for(int i = l; i <= r; i += k){
                nums[i] = (1LL * nums[i] * val) % mod;
            }
        }
        int ans = 0;
        for(int x : nums) ans ^= x;
        return ans;
    }
};