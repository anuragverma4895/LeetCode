class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, vector<int>> mp;

        for (auto x : reservedSeats) {
            mp[x[0]].push_back(x[1]);
        }

        int ans = (n - mp.size()) * 2;

        for (auto x : mp) {
            set<int> s(x.second.begin(), x.second.end());

            bool left = true;
            bool right = true;
            bool middle = true;

            for (int i = 2; i <= 5; i++) {
                if (s.count(i)) left = false;
            }

            for (int i = 6; i <= 9; i++) {
                if (s.count(i)) right = false;
            }

            for (int i = 4; i <= 7; i++) {
                if (s.count(i)) middle = false;
            }

            if (left && right)
                ans += 2;
            else if (left || right || middle)
                ans += 1;
        }

        return ans;
    }
};