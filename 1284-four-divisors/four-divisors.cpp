class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int x : nums){
            int cnt = 0;
            int a = 0, b = 0;
            for(int i = 2; i * i <= x; i++){
                if(x % i == 0){
                    cnt++;
                    a = i;
                    b = x / i;
                    if(cnt > 1) break;
                }
            }
            if(cnt == 1 && a != b){
                ans += 1 + a + b + x;
            }
        }
        return ans;
    }
};
