class Solution {
public:
    int minSwaps(string s) {
        int balance = 0;
        int maxBalance = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[') {
                balance++;
            } else {
                balance--;
            }
            maxBalance = min(maxBalance, balance);
        }
        return (-maxBalance + 1) / 2;
    }
};