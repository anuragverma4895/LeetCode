class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        vector<pair<int,int>> a, b;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(img1[i][j] == 1) a.push_back({i, j});
                if(img2[i][j] == 1) b.push_back({i, j});
            }
        }

        map<pair<int,int>, int> mp;
        int ans = 0;

        for(auto [x1, y1] : a) {
            for(auto [x2, y2] : b) {
                int dx = x1 - x2;
                int dy = y1 - y2;

                mp[{dx, dy}]++;
                ans = max(ans, mp[{dx, dy}]);
            }
        }

        return ans;
    }
};