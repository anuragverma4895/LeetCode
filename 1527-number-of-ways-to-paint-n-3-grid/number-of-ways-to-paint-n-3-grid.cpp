class Solution {
public:
    int numOfWays(int n) {
        long long mod = 1e9+7;
        long long same = 6, diff = 6;
        
        for(int i = 2; i <= n; i++) {
            long long ns = (same * 3 + diff * 2) % mod;
            long long nd = (same * 2 + diff * 2) % mod;
            same = ns;
            diff = nd;
        }
        
        return (same + diff) % mod;
    }
};