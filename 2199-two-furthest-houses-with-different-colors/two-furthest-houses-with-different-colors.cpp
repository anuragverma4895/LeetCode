class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        
        int a = 0, b = n - 1;
        while(colors[a] == colors[b]) b--;
        int ans1 = b - a;

        a = 0, b = n - 1;
        while(colors[a] == colors[b]) a++;
        int ans2 = b - a;

        return max(ans1, ans2);
    }
};