class Solution {
public:
    int firstoccurence(vector<int>& nums, int target,int low,int high){
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }else if(nums[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    int lastoccurence(vector<int>&nums,int target,int low,int high){
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }else if(nums[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        int low=0,high=nums.size()-1;
        ans[0]=firstoccurence(nums,target,low,high);
        ans[1]=lastoccurence(nums,target,low,high);
        return ans;
    }
};