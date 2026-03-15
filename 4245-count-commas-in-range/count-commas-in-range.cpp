class Solution {
public:
    int countCommas(int n) {
        if(n<100) return 0;
        int co=0;
        for(int i=1000;i<=n;i++){
            if(i>=1000 && i<=999999){
                co+=1;
            }else if(i>=1000000){
                co+=2;
            }
        }
        return co;
    }
};