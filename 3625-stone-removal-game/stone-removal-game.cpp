class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        bool aliceWin = false;

        while (stones > 0 && n >= stones) {
            n -= stones;
            stones--;
            aliceWin = !aliceWin;
        }

        return aliceWin;
    }
};