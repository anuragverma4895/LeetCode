class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int minele=INT_MAX;
        for(int x:nums) minele=min(minele,x);
        if(minele%2==1) return true;
        for(int x:nums){
            if(x%2==1) return false;
        }
        return true;
    }
};