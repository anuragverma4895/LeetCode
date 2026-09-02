class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        while (!pq.empty()) {
            auto [cost, x, y] = pq.top();
            pq.pop();
            
            if (cost != dist[x][y])
                continue;
            
            if (x == m - 1 && y == n - 1)
                return cost < health;
            
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                
                int newCost = cost + grid[nx][ny];
                
                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, nx, ny});
                }
            }
        }
        
        return false;
    }
};