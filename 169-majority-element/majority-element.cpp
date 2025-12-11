class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int winner=-1;
        int count=0;
        for(auto x:nums){
            if(count==0){
                count=1;
                winner=x;
            }else if(x==winner){
                count++;
            }else{
                count--;
            }
        }
        return winner;
    }
};