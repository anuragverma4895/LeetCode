class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> parent(n), size(n, 1);

        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };

        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b) return;

            if (size[a] < size[b])
                swap(a, b);

            parent[b] = a;
            size[a] += size[b];
        };

        for (auto &v : allowedSwaps)
            unite(v[0], v[1]);

        unordered_map<int, unordered_map<int, int>> freq;

        for (int i = 0; i < n; i++)
            freq[find(i)][source[i]]++;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int root = find(i);

            if (freq[root][target[i]] > 0)
                freq[root][target[i]]--;
            else
                ans++;
        }

        return ans;
    }
};