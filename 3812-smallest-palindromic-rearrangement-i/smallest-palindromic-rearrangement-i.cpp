class Solution {
public:

    // // TLE
    // bool checkpalindrome(string s){
    //     int n=s.size();
    //     for(int i=0;i<n;i++){
    //         if(s[i]!=s[n-i-1]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // string smallestPalindrome(string s) {
    //     sort(s.begin(),s.end());
    //     do{
            
    //         if(checkpalindrome(s)){
    //             return s;
    //         }

    //     }while(next_permutation(s.begin(),s.end()));
    //     return "";
    // }


    string smallestPalindrome(string s){
        vector<int>freq(26,0);
        for(auto x:s){
            freq[x-'a']++;
        }
        string left="",mid="";
        for(int i=0;i<26;i++){
            left+=string(freq[i]/2,char('a'+i));
            if(freq[i]%2){
                mid=char('a'+i);
            }
        }
        string right=left;
        reverse(right.begin(),right.end());
        return left+mid+right;
    }


};