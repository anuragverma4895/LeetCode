class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int N = n * m;
        
        vector<int> arr;
        for(auto &row : grid)
            for(auto x : row)
                arr.push_back(x % 12345);
        
        vector<int> pref(N,1), suff(N,1);
        
        for(int i=1;i<N;i++)
            pref[i] = (pref[i-1] * arr[i-1]) % 12345;
        
        for(int i=N-2;i>=0;i--)
            suff[i] = (suff[i+1] * arr[i+1]) % 12345;
        
        vector<vector<int>> res(n, vector<int>(m));
        
        for(int i=0;i<N;i++){
            int val = (pref[i] * suff[i]) % 12345;
            res[i/m][i%m] = val;
        }
        
        return res;
    }
};