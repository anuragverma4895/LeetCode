class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        
        for(int i = 1; i <= n; i++) {
            int x = i;
            bool good = false, bad = false;
            
            while(x) {
                int d = x % 10;
                
                if(d == 3 || d == 4 || d == 7) {
                    bad = true;
                    break;
                }
                
                if(d == 2 || d == 5 || d == 6 || d == 9) {
                    good = true;
                }
                
                x /= 10;
            }
            
            if(!bad && good) ans++;
        }
        
        return ans;
    }
};