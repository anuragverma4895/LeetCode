class Solution {
public:
    bool judgeSquareSum(int c) {
        long long low=0;
        long long high=sqrt(c);
        while(low<=high){
            long long a=low*low;
            long long b=high*high;
            if(a+b==c) return true;
            else if((a+b)>c) high--;
            else{
                low++;
            }
        }
        return false;
        
    }
};