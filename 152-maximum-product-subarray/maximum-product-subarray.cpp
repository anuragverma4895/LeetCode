class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        long long pre = 1, suff = 1;
        long long ans = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            if (pre == 0)pre = 1;
            if (suff == 0)suff = 1;
            pre *= arr[i];
            suff *= arr[n - i - 1];
            ans = max(ans, max(pre, suff));
        }
        return ans;
    }
};