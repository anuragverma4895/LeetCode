class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);
        int cnt = 0, cost = 0;

        for(int i = 0; i < n; i++){
            ans[i] += cost;
            if(boxes[i] == '1') cnt++;
            cost += cnt;
        }

        cnt = 0;
        cost = 0;
        for(int i = n - 1; i >= 0; i--){
            ans[i] += cost;
            if(boxes[i] == '1') cnt++;
            cost += cnt;
        }

        return ans;
    }
};
