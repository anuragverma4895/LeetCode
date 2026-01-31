class Solution {
public:
    char nextGreatestLetter(vector<char>& s, char target) {
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]>target){
                return s[i];
            }
        }
        return s[0];
    }
};