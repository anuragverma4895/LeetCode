class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        unordered_map<string, int> order = {{"electronics", 0},
                                            {"grocery", 1},
                                            {"pharmacy", 2},
                                            {"restaurant", 3}};

        vector<pair<int, string>> valid;

        for (int i = 0; i < code.size(); i++) {
            if (!isActive[i])
                continue;
            if (order.find(businessLine[i]) == order.end())
                continue;

            string& c = code[i];
            if (c.empty())
                continue;

            bool ok = true;
            for (char ch : c) {
                if (!isalnum(ch) && ch != '_') {
                    ok = false;
                    break;
                }
            }
            if (!ok)
                continue;

            valid.push_back({order[businessLine[i]], c});
        }

        sort(valid.begin(), valid.end(), [](auto& a, auto& b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second < b.second;
        });

        vector<string> ans;
        for (auto& p : valid)
            ans.push_back(p.second);
        return ans;
    }
};