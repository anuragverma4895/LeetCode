class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) {
            return false;
        }

        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }

        return true;
    }

    vector<int> factors(int x) {
        vector<int> f;

        for (int d = 2; d * d <= x; d++) {
            if (x % d == 0) {
                f.push_back(d);

                while (x % d == 0) {
                    x /= d;
                }
            }
        }

        if (x > 1) {
            f.push_back(x);
        }

        return f;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return 0;
        }

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            vector<int> f = factors(nums[i]);

            for (int p : f) {
                mp[p].push_back(i);
            }
        }

        queue<pair<int,int>> q;
        vector<int> vis(n, 0);

        q.push({0, 0});
        vis[0] = 1;

        unordered_set<int> used;

        while (!q.empty()) {
            auto [i, step] = q.front();
            q.pop();

            if (i == n - 1) {
                return step;
            }

            if (i - 1 >= 0 && !vis[i - 1]) {
                vis[i - 1] = 1;
                q.push({i - 1, step + 1});
            }

            if (i + 1 < n && !vis[i + 1]) {
                vis[i + 1] = 1;
                q.push({i + 1, step + 1});
            }

            int val = nums[i];

            if (isPrime(val) && !used.count(val)) {
                used.insert(val);

                for (int ni : mp[val]) {
                    if (!vis[ni]) {
                        vis[ni] = 1;
                        q.push({ni, step + 1});
                    }
                }
            }
        }

        return -1;
    }
};