
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 1; i < n; i++) {
            string temp = "";
            int j = 0;

            while (j < s.size()) {
                int count = 0;
                char ch = s[j];

                while (j < s.size() && s[j] == ch) {
                    count++;
                    j++;
                }

                temp += to_string(count);
                temp += ch;
            }

            s = temp;
        }

        return s;
    }
};
