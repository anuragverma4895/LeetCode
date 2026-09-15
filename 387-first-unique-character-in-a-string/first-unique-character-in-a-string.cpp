// class Solution {
// public:
//     int firstUniqChar(string s) {
//         vector<int>temp(26,0);
//         int n=s.size();
//         for(auto x:s){
//             temp[x-'a']++;
//         }
//         for(int i=0;i<n;i++){
//             if((temp[s[i]-'a']==1)){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]]==1)
                    return i;
            }
        }
        return -1;
    }
};