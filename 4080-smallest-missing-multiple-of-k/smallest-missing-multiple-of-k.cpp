class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int maxVal=0;
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%k==0){
                s.insert(nums[i]);
                if(maxVal<nums[i]){
                    maxVal=nums[i];
                }
            }   
        }
        for(int i=k;i<=maxVal;i+=k){
            if(s.find(i)==s.end()){
                return i;
            }
        }
        return maxVal+k;
    }
};