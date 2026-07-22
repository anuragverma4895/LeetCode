class Solution {
public:
    vector<int> parent, rank1;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (rank1[x] < rank1[y])
            parent[x] = y;
        else if (rank1[x] > rank1[y])
            parent[y] = x;
        else {
            parent[y] = x;
            rank1[x]++;
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        parent.resize(n);
        rank1.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto &p : pairs)
            unite(p[0], p[1]);

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++)
            mp[find(i)].push_back(i);

        for (auto &it : mp) {
            vector<int> &idx = it.second;
            string temp;

            for (int x : idx)
                temp += s[x];

            sort(idx.begin(), idx.end());
            sort(temp.begin(), temp.end());

            for (int i = 0; i < idx.size(); i++)
                s[idx[i]] = temp[i];
        }
        return s;
    }
};