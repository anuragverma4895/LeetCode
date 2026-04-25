class Solution {
public:
    bool validDigit(int n, int x) {
        string s=to_string(n);
        string a=to_string(x);
        int count=0;
        
        for(int i=0;i<s.size();i++){
            if(s[0]==a[0]){
                return false;
            }
            if(s[i]==a[0]){
                count++;
                break;
            }
        }
        if(count) return true;
        return false;
    }
};