class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // not working
        // int n=nums.size();
        // int sum=0;
        // int count=0;
        // int j=0;
        // int sum2=0;
        // int count2=0;
        // for(int i=0;i<n;i++){
        //     sum2+=nums[i];
        //     count2++;
        //     sum+=nums[i];
        //     count++;
        //     if(sum==k and count>=2 and sum%k==0) return true;
        //     while(sum>k){
        //         sum-=nums[j++];
        //         count--;
        //         if(sum==k and count>=2 and sum%k==0) return true;
        //     }

        // }
        // if(sum2%k==0 and count2>=2) return true;
        // int sum3=sum2;
        // // int count2
        // int tempc=count2;
        // for(int i=0;i<n;i++){
        //     sum2-=nums[i];
        //     tempc--;
        //     if(sum2%k==0 and tempc>=2) return true;
        // }
        // int sum4=sum3;
        // tempc=count2;
        // // int l=n-1;
        // for(int i=n-1;i>=0;i--){
        //     sum3-=nums[i];
        //     tempc--;
        //     if(sum3%k==0 and tempc>=2) return true;
        // }
        // return false;

        int n=nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;

        int prefix = 0;

        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            int rem = prefix % k;

            if (mp.count(rem)) {
                if (i - mp[rem] >= 2)
                    return true;
            } else {
                mp[rem] = i;
            }
        }
        return false;
    }
};