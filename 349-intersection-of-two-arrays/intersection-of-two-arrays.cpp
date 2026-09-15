// class Solution {
// public:
//     vector<int> intersection(vector<int>& a, vector<int>& b) {
//     unordered_set<int> s(a.begin(), a.end());
//     vector<int> ans;
//     for (int x : b) {
//         if (s.count(x)) {
//             ans.push_back(x);
//             s.erase(x);
//         }
//     }
//     return ans;
//     }
// };



class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<a.size();i++){
            if(mp.find(a[i])==mp.end()){
                mp[a[i]]++;
            }
        }
        for(int i=0;i<b.size();i++){
            if(mp.find(b[i])!=mp.end()){
                ans.push_back(b[i]);
                mp.erase(b[i]);
            }
        }
        return ans;
    }
};