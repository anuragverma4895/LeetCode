class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int groupSize) {
        int n = nums.size();
        if (n % groupSize != 0)
            return false;

        map<int, int> mp;
        for (int x : nums)
            mp[x]++;

        while (!mp.empty()) {
            int start = mp.begin()->first;
            for (int i = 0; i < groupSize; i++) {
                int val = start + i;
                if (mp[val] == 0)
                    return false;
                mp[val]--;
                if (mp[val] == 0)
                    mp.erase(val);
            }
        }
        return true;
    }
};