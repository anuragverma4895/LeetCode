class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        int cb=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a' and cb>0) return false;
            if(s[i]=='b') cb++;
        }
        return true;
    }
};