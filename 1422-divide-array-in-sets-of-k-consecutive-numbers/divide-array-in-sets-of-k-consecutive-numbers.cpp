class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0) return false;
        map<int,int>mp;
        for(int x:nums){
            mp[x]++;
        }
        while(!mp.empty()){
            int start=mp.begin()->first;
            for(int i=0;i<k;i++){
                int val=start+i;
                if(mp[val]==0){
                    return false;
                }
                mp[val]--;
                if(mp[val]==0){
                    mp.erase(val);
                }
            }
        }
        return true;
    }
};