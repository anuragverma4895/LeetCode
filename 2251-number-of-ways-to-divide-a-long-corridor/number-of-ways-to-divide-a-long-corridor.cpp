class Solution {
public:
    int numberOfWays(string corridor) {
        const long long MOD = 1e9 + 7;
        long long totalSeats = 0;
        for (char c : corridor)
            if (c == 'S')
                totalSeats++;
        if (totalSeats == 0 || totalSeats % 2)
            return 0;

        long long ans = 1;
        long long seatCnt = 0;
        long long plants = 0;

        for (char c : corridor) {
            if (c == 'S') {
                seatCnt++;
                if (seatCnt > 2 && seatCnt % 2 == 1) {
                    ans = (ans * (plants + 1)) % MOD;
                    plants = 0;
                }
            } else {
                if (seatCnt >= 2 && seatCnt % 2 == 0)
                    plants++;
            }
        }
        return ans;
    }
};