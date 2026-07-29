class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // // O(n^2)
        // int ans=0;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     int temp=0;
        //     for(int j=i+1;j<n;j++){
        //         temp=(nums[i]-1)*(nums[j]-1);
        //         ans=max(temp, ans);
        //     }
        // }
        // return ans;


        // // O(nlogn)
        // int n=nums.size();
        // sort(nums.begin(),nums.end(),greater<int>());
        // return (nums[0]-1)*(nums[1]-1);

        int n=nums.size();
        int first=0,second=0;
        for(int i=0;i<n;i++){
            if(nums[i]>first){
                second=first;
                first=nums[i];
            }
            else if(nums[i]>second){
                second=nums[i];
            }
        }
        cout<<first<<endl;
        cout<<second<<endl;
        return (first-1)*(second-1);
    }
};