class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> colX(n, 0), colY(n, 0);
        int ans = 0;
        
        for (int i = 0; i < m; ++i) {
            int currX = 0, currY = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'X') {
                    colX[j]++;
                } else if (grid[i][j] == 'Y') {
                    colY[j]++;
                }
                
                currX += colX[j];
                currY += colY[j];
                
                if (currX > 0 && currX == currY) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};