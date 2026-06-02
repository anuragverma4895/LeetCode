// class Solution {
// public:
//     int compareBitonicSums(vector<int>& n) {
//         long long s=n.size();
//         long long p=0;
//         for(long long i =0;i<s-1;i++){
//             if(n[i]>n[i+1]){
//                 p=i;
//                 break;
//             }
//         }
//         long long a=0;
//         long long d=0;
//         for(long long i=0;i<=p;i++){
//             a+=n[i];   
//         }
//         for(long long i=p;i<s;i++){
//             d+=n[i];
//         }
//         if(a>d) return 0;
//         if(d>a) return 1;
//         return -1;
//     }
// };




class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> p;
        
        for (auto &v : points) {
            long long x = v[0], y = v[1];

            if (x == 0) p.push_back(y);
            else if (y == side) p.push_back(side + x);
            else if (x == side) p.push_back(3LL * side - y);
            else p.push_back(4LL * side - x);
        }

        sort(p.begin(), p.end());

        auto check = [&](long long d) {
            long long per = 4LL * side;

            for (long long start : p) {
                long long limit = start + per - d;
                long long cur = start;
                bool ok = true;

                for (int i = 1; i < k; i++) {
                    auto it = lower_bound(p.begin(), p.end(), cur + d);

                    if (it == p.end() || *it > limit) {
                        ok = false;
                        break;
                    }

                    cur = *it;
                }

                if (ok) return true;
            }

            return false;
        };

        long long l = 1, r = side;

        while (l < r) {
            long long mid = (l + r + 1) / 2;

            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }

        return l;
    }
};