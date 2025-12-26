class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int totalY = 0;
        for(char c : customers) if(c == 'Y') totalY++;
        int penalty = totalY;
        int minPenalty = penalty;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(customers[i] == 'N') penalty++;
            else penalty--;
            if(penalty < minPenalty) {
                minPenalty = penalty;
                ans = i + 1;
            }
        }
        return ans;
    }
};
