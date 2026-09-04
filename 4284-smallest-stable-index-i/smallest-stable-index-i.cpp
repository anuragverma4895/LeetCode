class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>minvalue(n);
        minvalue[n-1]=nums[n-1];
        vector<int>maxvalue(n);
        maxvalue[0]=nums[0];
        for(int i=1;i<n;i++){
            maxvalue[i]=max(maxvalue[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            minvalue[i]=min(minvalue[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            if(maxvalue[i]-minvalue[i]<=k){
                return i;
            }
        }
        return -1;
    }
};