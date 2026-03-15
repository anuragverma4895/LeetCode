class Solution {
public:
    long long countCommas(long long n) {
        long long re=0;
        long th=1000;
        while(n>=th){
            re+=(n-th+1);
            th*=1000;
        }
        return re;
    }
};