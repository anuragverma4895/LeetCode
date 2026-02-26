class Solution {
public:
    int numSteps(string s) {
        // TLE because size is 56 and that will consider as 2^56
        // unsigned __int128 a=stoi(s,0,2);
        // unsigned __int128 n=a;
        // unsigned __int128 ans=0;
        // while(n!=1){
        //     if(n%2!=0){
        //         n+=1;
        //         ans++;
        //     }else if(n%2==0){
        //         ans++;
        //         n/=2;
        //     }
        // }
        // return ans;

        // let operate in string directly
        int ans=0;
        int carry=0;
        for(int i=s.size()-1;i>0;i--){
            if((s[i]-'0'+carry)%2==1){
                ans+=2;
                carry=1;
            }else{
                ans+=1;
            }
        }
        return ans+carry;
    }
};