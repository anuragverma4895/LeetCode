#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        string current;
        backtrack(n, happyStrings, current);
        if (k > happyStrings.size()) {
            return "";
        }
        return happyStrings[k - 1];
    }
    
private:
    void backtrack(int n, vector<string>& happyStrings, string& current) {
        if (current.size() == n) {
            happyStrings.push_back(current);
            return;
        }
        for (char c : {'a', 'b', 'c'}) {
            if (current.empty() || current.back() != c) {
                current.push_back(c);
                backtrack(n, happyStrings, current);
                current.pop_back();
            }
        }
    }
};