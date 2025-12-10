class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos,neg;
        for(int x:nums){
            if(x>0){
                pos.push_back(x);
            }else{
                neg.push_back(x);
            }
        }
        vector<int>ans;
        for(int i=0;i<nums.size()/2;i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};