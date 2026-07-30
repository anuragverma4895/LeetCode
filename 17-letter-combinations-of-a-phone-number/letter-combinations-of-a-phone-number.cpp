class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void dfs(string &digits, int idx, string &cur) {
        if (idx == digits.size()) {
            ans.push_back(cur);
            return;
        }

        for (char c : mp[digits[idx] - '0']) {
            cur.push_back(c);
            dfs(digits, idx + 1, cur);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        string cur;
        dfs(digits, 0, cur);
        return ans;
    }
};