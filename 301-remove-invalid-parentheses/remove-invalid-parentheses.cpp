class Solution {
public:
    bool isValid(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count++;
            }
            else if (s[i] == ')') {
                count--;

                if (count < 0) {
                    return false;
                }
            }
        }
        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        queue<string> q;
        unordered_set<string> visited;
        q.push(s);
        visited.insert(s);
        bool found = false;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string current = q.front();
                q.pop();
                if (isValid(current)) {
                    ans.push_back(current);
                    found = true;
                }
                if (found) {
                    continue;
                }
                for (int j = 0; j < current.size(); j++) {
                    if (current[j] != '(' && current[j] != ')') {
                        continue;
                    }
                    string next = current.substr(0, j) + current.substr(j + 1);

                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            if (found) {
                break;
            }
        }
        return ans;
    }
};