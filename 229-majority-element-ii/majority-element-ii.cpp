class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        int cand1=0, count1=0;
        int cand2=0, count2=0;
        for(int i=0;i<n;i++){
            if(count1==0 && cand2!=nums[i]){
                count1++;
                cand1=nums[i];
            }else if(count2==0 && cand1!=nums[i]){
                count2++;
                cand2=nums[i];
            }else if(cand1==nums[i]){
                count1++;
            }else if(cand2==nums[i]){
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==cand1) count1++;
            if(nums[i]==cand2) count2++;
        }
        if(n/3<count1) ans.push_back(cand1);
        if(n/3<count2){
            if(cand1!=cand2)
            ans.push_back(cand2);
        } 
        return ans;
    }
};