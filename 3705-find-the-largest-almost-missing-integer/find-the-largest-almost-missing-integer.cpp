class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int ans = -1;

        for (int x = 0; x <= 50; x++) {
            int count = 0;

            for (int i = 0; i <= nums.size() - k; i++) {
                bool found = false;

                for (int j = i; j < i + k; j++) {
                    if (nums[j] == x) {
                        found = true;
                        break;
                    }
                }

                if (found)
                    count++;
            }

            if (count == 1)
                ans = x;
        }

        return ans;
    }
};