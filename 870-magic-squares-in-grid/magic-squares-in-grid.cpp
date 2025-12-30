class Solution {
public:
    bool isMagic(vector<vector<int>>& g, int r, int c) {
        vector<int> cnt(10, 0);
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int v = g[i][j];
                if (v < 1 || v > 9)
                    return false;
                cnt[v]++;
            }
        }
        for (int i = 1; i <= 9; i++)
            if (cnt[i] != 1)
                return false;
        if (g[r + 1][c + 1] != 5)
            return false;
        int s = g[r][c] + g[r][c + 1] + g[r][c + 2];
        if (g[r + 1][c] + g[r + 1][c + 1] + g[r + 1][c + 2] != s)
            return false;
        if (g[r + 2][c] + g[r + 2][c + 1] + g[r + 2][c + 2] != s)
            return false;
        if (g[r][c] + g[r + 1][c] + g[r + 2][c] != s)
            return false;
        if (g[r][c + 1] + g[r + 1][c + 1] + g[r + 2][c + 1] != s)
            return false;
        if (g[r][c + 2] + g[r + 1][c + 2] + g[r + 2][c + 2] != s)
            return false;
        if (g[r][c] + g[r + 1][c + 1] + g[r + 2][c + 2] != s)
            return false;
        if (g[r][c + 2] + g[r + 1][c + 1] + g[r + 2][c] != s)
            return false;
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i + 2 < n; i++) {
            for (int j = 0; j + 2 < m; j++) {
                if (isMagic(grid, i, j))
                    ans++;
            }
        }
        return ans;
    }
};