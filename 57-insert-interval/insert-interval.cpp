// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         intervals.push_back(newInterval);

//         sort(intervals.begin(), intervals.end());

//         vector<vector<int>> ans;
//         ans.push_back(intervals[0]);

//         for(int i = 1; i < intervals.size(); i++) {
//             if(intervals[i][0] <= ans.back()[1]) {
//                 ans.back()[1] = max(ans.back()[1], intervals[i][1]);
//             } else {
//                 ans.push_back(intervals[i]);
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        int st = newInterval[0];
        int ed = newInterval[1];
        bool inserted = false;

        for (auto &it : intervals) {
            int s = it[0];
            int e = it[1];

            if (e < st) {
                ans.push_back(it);
            }
            else if (s > ed) {
                if (!inserted) {
                    ans.push_back({st, ed});
                    inserted = true;
                }
                ans.push_back(it);
            }
            else {
                st = min(st, s);
                ed = max(ed, e);
            }
        }

        if (!inserted) {
            ans.push_back({st, ed});
        }

        return ans;
    }
};