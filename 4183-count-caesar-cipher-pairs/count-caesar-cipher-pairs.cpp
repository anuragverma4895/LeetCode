class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, int> mp;
        long long ans = 0;

        for (string s : words) {
            string key;

            for (int i = 0; i < s.size(); i++) {
                int diff = (s[i] - s[0] + 26) % 26;
                key += char('a' + diff);
            }

            ans += mp[key];
            mp[key]++;
        }

        return ans;
    }
};