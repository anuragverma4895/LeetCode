class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> vis(n + 1, 0);
        int ans = INT_MAX;

        queue<int> q;
        q.push(1);
        vis[1] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto [v, w] : adj[u]) {
                ans = min(ans, w);

                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};