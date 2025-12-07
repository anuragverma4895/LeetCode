class Solution {
public:
    int countOdds(int low, int high) {
        int n=low;
        int count=0;
        while(n<=high){
            if(n%2!=0){
                count++;
            }
            n++;
        }
        return count;
    }
};