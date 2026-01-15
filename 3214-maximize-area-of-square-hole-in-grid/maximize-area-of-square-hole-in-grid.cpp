class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        auto f = [&](vector<int>& a) {
            sort(a.begin(), a.end());
            int mx = 1, cur = 1;
            for (int i = 1; i < a.size(); i++) {
                if (a[i] == a[i-1] + 1) cur++;
                else cur = 1;
                mx = max(mx, cur);
            }
            return mx + 1;
        };
        int h = f(hBars);
        int v = f(vBars);
        int s = min(h, v);
        return s * s;
    }
};
