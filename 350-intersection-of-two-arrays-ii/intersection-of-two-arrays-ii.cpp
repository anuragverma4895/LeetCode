// class Solution {
// public:
//     vector<int> intersect(vector<int>& a, vector<int>& b) {
//         unordered_map<int,int>freq;
//         for(int x:a){
//             freq[x]++;
//         } 
//         vector<int>ans;
//         for(int x:b){
//             if(freq[x]>0){
//                 freq[x]--;
//                 ans.push_back(x);
//             }
//         }
//         return ans;
//     }
// };



class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<a.size();i++){
            mp[a[i]]++;
        }

        for(int i=0;i<b.size();i++){
            if(mp.find(b[i])!=mp.end()){
                mp[b[i]]--;
                if(mp[b[i]]==0){
                    mp.erase(b[i]);
                }
                ans.push_back(b[i]);
            }
        }
        return ans;
    }
};