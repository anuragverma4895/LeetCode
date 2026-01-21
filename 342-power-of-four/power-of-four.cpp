class Solution {
public:
    bool isPowerOfFour(int n) {
        // int temp=pow(4,15);
        // return n>0 && temp%n==0 && (n & 0x55555555);

        return n > 0 && (n & (n - 1)) == 0 && ((n & 0x55555555)!=0);
    }
};