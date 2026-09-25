class Solution {
public:
    set<string> solve(string &s, int &i) {
        set<string> res;
        set<string> cur;
        cur.insert("");

        while (i <= s.size() && s[i] != '}') {
            if (s[i] == ',') {
                for (auto x : cur) res.insert(x);
                cur.clear();
                cur.insert("");
                i++;
            }
            else if (s[i] == '{') {
                i++;
                set<string> temp = solve(s, i);
                i++;

                set<string> next;
                for (auto a : cur) {
                    for (auto b : temp) {
                        next.insert(a + b);
                    }
                }
                cur = next;
            }
            else {
                string x(1, s[i]);
                set<string> next;

                for (auto a : cur) {
                    next.insert(a + x);
                }

                cur = next;
                i++;
            }
        }

        for (auto x : cur) res.insert(x);

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};