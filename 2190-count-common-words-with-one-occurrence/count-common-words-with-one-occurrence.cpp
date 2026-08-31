class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> a, b;

        for (string &s : words1) a[s]++;
        for (string &s : words2) b[s]++;

        int ans = 0;

        for (auto &it : a) {
            if (it.second == 1 && b[it.first] == 1)
                ans++;
        }

        return ans;
    }
};