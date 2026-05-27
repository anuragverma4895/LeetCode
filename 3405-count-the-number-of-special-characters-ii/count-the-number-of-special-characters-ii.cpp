class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> state(26, -1);
        for(char ch : word) {
            int idx = tolower(ch) - 'a';
            if(islower(ch)) {
                if(state[idx] == -1)
                    state[idx] = 1;
                else if(state[idx] == 0)
                    state[idx] = 2;
                else if(state[idx] == 3)
                    state[idx] = 2;
            }
            else {
                if(state[idx] == 1)
                    state[idx] = 0;

                else if(state[idx] == -1)
                    state[idx] = 3;
            }
        }
        int ans = 0;
        for(int x : state) {
            if(x == 0)
                ans++;
        }
        return ans;
    }
};