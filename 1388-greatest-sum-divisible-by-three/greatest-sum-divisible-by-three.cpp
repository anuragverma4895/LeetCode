class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> m1;
        vector<int> m2; 
        for (int x : nums) {
            sum += x;
            if (x % 3 == 1) m1.push_back(x);
            else if (x % 3 == 2) m2.push_back(x);
        }
        if (sum % 3 == 0) return sum;
        sort(m1.begin(), m1.end());
        sort(m2.begin(), m2.end());
        int ans = 0;
        if (sum % 3 == 1) {
            int op1 = 1e9, op2 = 1e9;
            if (!m1.empty()) op1 = m1[0];
            if (m2.size() >= 2) op2 = m2[0] + m2[1];
            ans = sum - min(op1, op2);
        } 
        else {
            int op1 = 1e9, op2 = 1e9;
            if (!m2.empty()) op1 = m2[0];
            if (m1.size() >= 2) op2 = m1[0] + m1[1];
            ans = sum - min(op1, op2);
        }

        return ans < 0 ? 0 : ans;
    }
};
