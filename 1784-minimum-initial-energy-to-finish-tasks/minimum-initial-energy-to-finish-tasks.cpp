class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int energy = 0;
        int ans = 0;

        for(auto &t : tasks) {
            if(energy < t[1]) {
                ans += (t[1] - energy);
                energy = t[1];
            }

            energy -= t[0];
        }

        return ans;
    }
};