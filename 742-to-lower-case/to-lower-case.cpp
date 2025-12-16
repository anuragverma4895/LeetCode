class Solution {
public:
    string toLowerCase(string s) {
        string k="";
        for(int i=0;i<s.size();i++){
            k+=tolower(s[i]);
        }
        s=k;
        return s;
    }
};