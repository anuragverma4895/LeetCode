class Solution {
public:
    long long mod=1e9+7;

    long long power(long long a,long long b){
        long long res=1;
        a%=mod;
        while(b){
            if(b&1) res=(res*a)%mod;
            a=(a*a)%mod;
            b>>=1;
        }
        return res;
    }

    int minNonZeroProduct(int p) {
        long long mx=(1LL<<p)-1;
        long long base=(mx-1)%mod;
        long long exp=(1LL<<(p-1))-1;

        long long ans=power(base,exp);
        ans=(ans*(mx%mod))%mod;
        return ans;
    }
};