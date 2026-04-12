class Solution {
public:
    int kthGrammar(int n, int k) {
        // TLE
        // vector<string>temp;
        // temp.push_back("0");
        // for(int i=0;i<=n;i++){
        //     string s="";
        //     string k=temp[i];
        //     for(int j=0;j<k.size();j++){
        //         if(k[j]=='0'){
        //             s+="01";
        //         }else if(k[j]=='1'){
        //             s+="10";
        //         }
        //     }
        //     temp.push_back(s);
        // }
        // string a = temp[n];
        // return a[m-1]-'0';

        return __builtin_popcount(k-1) % 2;
    }
};