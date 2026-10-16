
class LazySegmentTree {
public:
    int n;
    long long MOD = 1000000007;
    vector<long long> sum, squareSum, lazy;

    LazySegmentTree(int size) {
        n = size;
        sum.assign(4 * n, 0);
        squareSum.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void push(int node, int start, int end) {
        if (lazy[node] == 0) {
            return;
        }

        long long val = lazy[node];
        long long len = end - start + 1;

        squareSum[node] =
            (squareSum[node] + 2 * val * sum[node] % MOD
             + val * val % MOD * len % MOD) % MOD;

        sum[node] = (sum[node] + val * len) % MOD;

        if (start != end) {
            lazy[node * 2] = (lazy[node * 2] + val) % MOD;
            lazy[node * 2 + 1] = (lazy[node * 2 + 1] + val) % MOD;
        }

        lazy[node] = 0;
    }

    void update(int node, int start, int end, int left, int right) {
        push(node, start, end);

        if (start > right || end < left) {
            return;
        }

        if (start >= left && end <= right) {
            lazy[node] = 1;
            push(node, start, end);
            return;
        }

        int mid = start + (end - start) / 2;

        update(node * 2, start, mid, left, right);
        update(node * 2 + 1, mid + 1, end, left, right);

        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;

        squareSum[node] =
            (squareSum[node * 2] + squareSum[node * 2 + 1]) % MOD;
    }

    void updateRange(int left, int right) {
        update(1, 0, n - 1, left, right);
    }

    long long getSquareSum() {
        return squareSum[1];
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const long long MOD = 1000000007;
        int n = nums.size();

        LazySegmentTree tree(n);
        unordered_map<int, int> lastSeen;

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int left = 0;

            if (lastSeen.find(nums[i]) != lastSeen.end()) {
                left = lastSeen[nums[i]] + 1;
            }

            tree.updateRange(left, i);

            lastSeen[nums[i]] = i;

            ans = (ans + tree.getSquareSum()) % MOD;
        }

        return ans;
    }
};
