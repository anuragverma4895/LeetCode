class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>arr;
        int val=0;
        for(auto bit:nums){
            val = (val * 2 + bit) % 5;
            arr.push_back(val == 0);
        }
        return arr;
    }
};