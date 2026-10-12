class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        int mod = 1000000007;

        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                int mid = st.top();
                st.pop();

                int left = -1;

                if (!st.empty()) {
                    left = st.top();
                }

                long long leftCount = mid - left;
                long long rightCount = i - mid;

                ans = (ans + arr[mid] * leftCount % mod * rightCount % mod) % mod;
            }

            st.push(i);
        }

        while (!st.empty()) {
            int mid = st.top();
            st.pop();

            int left = -1;

            if (!st.empty()) {
                left = st.top();
            }

            long long leftCount = mid - left;
            long long rightCount = n - mid;

            ans = (ans + arr[mid] * leftCount % mod * rightCount % mod) % mod;
        }

        return ans;
    }
};