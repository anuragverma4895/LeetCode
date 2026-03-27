class Solution {
public:
    int solve2(string &s, char x, char y) {
        unordered_map<int,int> mp;
        int cx = 0, cy = 0, ans = 0;

        mp[0] = -1;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] != x && s[i] != y) {
                mp.clear();
                mp[0] = i;
                cx = cy = 0;
                continue;
            }

            if(s[i] == x) cx++;
            else cy++;

            int d = cx - cy;

            if(mp.count(d)) ans = max(ans, i - mp[d]);
            else mp[d] = i;
        }
        return ans;
    }

    int solve3(string &s) {
        map<pair<int,int>, int> mp;
        mp[{0,0}] = -1;

        int a = 0, b = 0, c = 0, ans = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a') a++;
            else if(s[i] == 'b') b++;
            else c++;

            int d1 = a - b;
            int d2 = a - c;

            if(mp.count({d1, d2})) ans = max(ans, i - mp[{d1, d2}]);
            else mp[{d1, d2}] = i;
        }
        return ans;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) cnt++;
            else cnt = 1;
            ans = max(ans, cnt);
        }
        ans = max(ans, 1);
        ans = max(ans, solve2(s, 'a', 'b'));
        ans = max(ans, solve2(s, 'a', 'c'));
        ans = max(ans, solve2(s, 'b', 'c'));
        ans = max(ans, solve3(s));

        return ans;
    }
};