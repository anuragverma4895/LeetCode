#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<int> st;
        int ans = 0;
        
        for(int i = 0; i <= n; i++) {
            int cur = (i == n ? 0 : h[i]);
            while(!st.empty() && h[st.top()] > cur) {
                int height = h[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, height * width);
            }
            st.push(i);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        
        int n = matrix.size(), m = matrix[0].size();
        vector<int> h(m, 0);
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') h[j]++;
                else h[j] = 0;
            }
            ans = max(ans, largestRectangleArea(h));
        }
        return ans;
    }
};