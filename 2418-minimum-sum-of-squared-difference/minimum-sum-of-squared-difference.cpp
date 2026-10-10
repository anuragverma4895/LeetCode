class Solution {
public:
    long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        
        std::vector<long long> bucket(100001, 0);
        int max_diff = 0;
        
        for (int i = 0; i < n; ++i) {
            int diff = std::abs(nums1[i] - nums2[i]);
            bucket[diff]++;
            max_diff = std::max(max_diff, diff);
        }
        
        for (int d = max_diff; d > 0; --d) {
            if (bucket[d] > 0) {
                long long take = std::min(bucket[d], k);
                bucket[d] -= take;
                bucket[d - 1] += take;
                k -= take;
                if (k == 0) break;
            }
        }
        
        long long min_squared_sum = 0;
        for (long long d = 1; d <= max_diff; ++d) {
            if (bucket[d] > 0) {
                min_squared_sum += bucket[d] * d * d;
            }
        }
        
        return min_squared_sum;
    }
};
