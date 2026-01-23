class Solution {
public:

    int bitDifference(int a, int b){
    int x = a ^ b;
    int cnt = 0;
    while(x){
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}
    int minOperations(vector<int>& nums, int k) {
        int fxor=0;
        for(int i=0;i<nums.size();i++){
            fxor^=nums[i];
        }
        return bitDifference(fxor,k);
    }
};