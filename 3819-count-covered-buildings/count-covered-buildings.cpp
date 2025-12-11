class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int,int>> row;
        unordered_map<int, pair<int,int>> col;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            if (!row.count(x)) row[x] = {y, y};
            else {
                row[x].first = min(row[x].first, y);
                row[x].second = max(row[x].second, y);
            }

            if (!col.count(y)) col[y] = {x, x};
            else {
                col[y].first = min(col[y].first, x);
                col[y].second = max(col[y].second, x);
            }
        }

        int ans = 0;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            auto [minY, maxY] = row[x];
            auto [minX, maxX] = col[y];

            bool left  = y > minY;
            bool right = y < maxY;
            bool up    = x > minX;
            bool down  = x < maxX;

            if (left && right && up && down)
                ans++;
        }
        return ans;
    }
};
