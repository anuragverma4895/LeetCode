class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<int,int>mp;
        for(int i=0;i<m.size();i++){
            mp[m[i]]++;
        }
        for(int i=0;i<r.size();i++){
            if(mp.find(r[i])==mp.end()){
                return false;
            }
            if(mp[r[i]]==0) return false;
            mp[r[i]]--;
        }
        return true;
    }
};