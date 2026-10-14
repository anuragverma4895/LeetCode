class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        pair<int, int>drevantor={num,sum};
        if(sum>9*num) return "";
        string res="";
        for(int i=0;i<num;++i){
            int d=min(9,sum);
            res.push_back('0'+d);
            sum-=d;
        }
        return res;
    }
};