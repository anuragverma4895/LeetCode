class Solution {
public:
    int atMost(vector<int>& nums, int goal){
        if(goal < 0) return 0;

        int n = nums.size();
        int sum = 0;
        int j = 0;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];

            while(sum > goal){
                sum -= nums[j++];
            }

            cnt += (i - j + 1);
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};