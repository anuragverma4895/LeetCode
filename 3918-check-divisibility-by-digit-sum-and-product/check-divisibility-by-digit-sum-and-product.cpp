class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int m=n;
        while(m){
            int a=m%10;
            sum+=a;
            product*=a;
            m/=10;
        }
        return n%(sum+product)==0;
    }
};