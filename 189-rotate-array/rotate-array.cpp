class Solution {
public:
    // int rotate1(vector<int>&v, int i, int j){
    //     while(i<j){
    //         swap(v[i],v[j]);
    //         i++;
    //         j--;
    //     }
    //     return 0;
    // }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return;
        k%=n;
    //     rotate1(nums,n-k,n-1);
    //     rotate1(nums,0,n-k-1);
    //     rotate1(nums,0,n-1);
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());

    }
};