// class Solution {
// public:
//     int maximumGroups(vector<int>& grades) {
//         int n = grades.size();

//         int l = 1, r = n, ans = 0;

//         while (l <= r) {
//             int mid = l + (r - l) / 2;

//             long long need = 1LL * mid * (mid + 1) / 2;

//             if (need <= n) {
//                 ans = mid;
//                 l = mid + 1;
//             } else {
//                 r = mid - 1;
//             }
//         }

//         return ans;
//     }
// };


class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();

        int k = 0;
        while ((k + 1) * (k + 2) / 2 <= n) {
            k++;
        }

        return k;
    }
};