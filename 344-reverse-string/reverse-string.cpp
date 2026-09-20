// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         // int n=s.size();
//         // for(int i=0;i<n/2;i++){
//         //     swap(s[i],s[n-i-1]);
//         // }
//         reverse(s.begin(),s.end());
//     }
// };


class Solution {
public:
    void f(vector<char>&s,int i,int sz,int n){
        if(i>=sz) return;
        swap(s[i],s[n-i-1]);
        f(s,i+1,sz,n);
    }
    void reverseString(vector<char>& s) {
        f(s,0,s.size()/2,s.size());
        
    }
};