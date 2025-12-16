class Solution {
public:
    int B;
    vector<vector<int>> g;
    vector<int> p, f;
    vector<vector<vector<int>>> dp;

    void dfs(int u) {
        for (int v : g[u])
            dfs(v);

        for (int pb = 0; pb <= 1; pb++) {
            dp[u][pb].assign(B + 1, -1e9);
            dp[u][pb][0] = 0;

            vector<int> base(B + 1, -1e9);
            base[0] = 0;

            for (int v : g[u]) {
                vector<int> nxt(B + 1, -1e9);
                for (int i = 0; i <= B; i++)
                    if (base[i] > -1e8) {
                        for (int j = 0; i + j <= B; j++) {
                            nxt[i + j] = max(nxt[i + j], base[i] + dp[v][0][j]);
                        }
                    }
                base.swap(nxt);
            }

            for (int i = 0; i <= B; i++)
                dp[u][pb][i] = max(dp[u][pb][i], base[i]);

            int cost = pb ? p[u] / 2 : p[u];
            int gain = f[u] - cost;

            if (cost <= B) {
                vector<int> take(B + 1, -1e9);
                take[cost] = gain;

                for (int v : g[u]) {
                    vector<int> nxt(B + 1, -1e9);
                    for (int i = 0; i <= B; i++)
                        if (take[i] > -1e8) {
                            for (int j = 0; i + j <= B; j++) {
                                nxt[i + j] =
                                    max(nxt[i + j], take[i] + dp[v][1][j]);
                            }
                        }
                    take.swap(nxt);
                }

                for (int i = 0; i <= B; i++)
                    dp[u][pb][i] = max(dp[u][pb][i], take[i]);
            }
        }
    }

    int maxProfit(int n, vector<int>& present, vector<int>& future,
                  vector<vector<int>>& hierarchy, int budget) {
        B = budget;
        g.assign(n + 1, {});
        p.assign(n + 1, 0);
        f.assign(n + 1, 0);
        dp.assign(n + 1, vector<vector<int>>(2));

        for (int i = 1; i <= n; i++) {
            p[i] = present[i - 1];
            f[i] = future[i - 1];
        }

        for (auto& e : hierarchy)
            g[e[0]].push_back(e[1]);

        dfs(1);

        int ans = 0;
        for (int i = 0; i <= B; i++)
            ans = max(ans, dp[1][0][i]);
        return ans;
    }
};
