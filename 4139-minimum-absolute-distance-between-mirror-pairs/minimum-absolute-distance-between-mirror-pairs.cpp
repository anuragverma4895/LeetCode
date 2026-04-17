class Solution {
public:
    int rev(int x){
        int r = 0;
        while(x){
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 1e9;

        for(int i = 0; i < nums.size(); i++){
            if(mp.count(nums[i])) ans = min(ans, i - mp[nums[i]]);
            
            int r = rev(nums[i]);
            mp[r] = i;
        }

        return ans == 1e9 ? -1 : ans;
    }
};