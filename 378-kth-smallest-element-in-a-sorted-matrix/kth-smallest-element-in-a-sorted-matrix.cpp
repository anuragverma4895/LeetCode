class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // brute force
        // int n=matrix.size();
        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         ans.push_back(matrix[i][j]);
        //     }
        // }
        // sort(ans.begin(),ans.end());
        // return ans[k-1];


        int n=matrix.size();
        int lo=matrix[0][0],hi=matrix[n-1][n-1];
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            int count=0;
            int j=n-1;
            for(int i=0;i<n;i++){
                while(j>=0 && matrix[i][j]>mid){
                    j--;
                }
                count+=(j+1);
            }
            if(count<k){
                lo=mid+1;
            }else{
                hi=mid;
            }
        }
        return lo;
    }
};