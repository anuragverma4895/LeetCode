class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        if(rows == 0) return "";
        int n = s.size();
        int cols = n / rows;
        
        string ans = "";
        
        for(int j = 0; j < cols; j++){
            int i = 0, k = j;
            while(i < rows && k < cols){
                ans.push_back(s[i * cols + k]);
                i++;
                k++;
            }
        }
        
        while(!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};