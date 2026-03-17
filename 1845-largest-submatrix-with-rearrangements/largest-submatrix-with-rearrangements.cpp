class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        for(int j = 0; j < m; j++){
            for(int i = 1; i < n; i++){
                if(matrix[i][j]) matrix[i][j] += matrix[i-1][j];
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            vector<int> v = matrix[i];
            sort(v.rbegin(), v.rend());
            
            for(int j = 0; j < m; j++){
                ans = max(ans, v[j] * (j + 1));
            }
        }
        
        return ans;
    }
};