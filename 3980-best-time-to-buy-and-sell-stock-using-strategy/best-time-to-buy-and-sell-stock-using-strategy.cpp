class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> prefOld(n + 1, 0), prefPrice(n + 1, 0);
        long long origProfit = 0;
        
        for(int i = 0; i < n; i++) {
            origProfit += 1LL * strategy[i] * prices[i];
            prefOld[i + 1] = prefOld[i] + 1LL * strategy[i] * prices[i];
            prefPrice[i + 1] = prefPrice[i] + prices[i];
        }
        
        long long bestGain = 0;
        int half = k / 2;
        
        for(int l = 0; l + k <= n; l++) {
            int r = l + k;
            long long oldVal = prefOld[r] - prefOld[l];
            long long newVal = prefPrice[r] - prefPrice[l + half];
            bestGain = max(bestGain, newVal - oldVal);
        }
        
        return origProfit + bestGain;
    }
};
