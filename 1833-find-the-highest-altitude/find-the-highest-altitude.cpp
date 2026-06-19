class Solution {
public:
    int curr = 0, ans = 0;
    int largestAltitude(vector<int>& gain) {
        for (int i = 0; i < gain.size(); i++) {
            curr += gain[i];
            ans = max(ans, curr);
        }
        return ans;
    }
};