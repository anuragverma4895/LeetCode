class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        // O(nlongn)
        // vector<int>ans;
        // sort(nums.begin(),nums.end());
        // int a=nums[0];
        // for(int i=1;i<nums.size();){
        //     if(a+1!=nums[i]){
        //         ans.push_back(a+1);
        //         a=a+1;
        //     }else{
        //         a=nums[i];
        //         i++;
        //     }
        // }
        // return ans;

        vector<int>ans;
        vector<int>freq(101,0);
        int min1=INT_MAX;
        int max1=INT_MIN;
        for(int x:nums){
            if(x>max1) max1=x;
            if(x<min1) min1=x;
            freq[x]++;
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i]==0 and i<max1 and i>min1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};