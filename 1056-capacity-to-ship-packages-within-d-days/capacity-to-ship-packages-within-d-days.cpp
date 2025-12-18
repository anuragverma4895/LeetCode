class Solution {
public:

    bool is_possible(vector<int>&sz,int days,int cap){
        int cnt_day=1;
        int shipped=0;
        for(int i=0;i<sz.size();i++){
            if(shipped +sz[i]<=cap){
                shipped+=sz[i];
            }else{
                cnt_day+=1;
                shipped=0;
                shipped+=sz[i];
            }
        }
        if(cnt_day<=days){
            return true;
        }
        return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int min_cap=*max_element(weights.begin(),weights.end());
        int sum=accumulate(weights.begin(),weights.end(),0);
        // sum=0; for(auto x:weights) sum+=x;

        // brute force -> TLE
        // for(int i=min_cap;i<=sum;i++){
        //     if(is_possible(weights,days,i)){
        //         return i;
        //     }
        // }
        // return -1;

        int low=min_cap;
        int high=sum;
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(is_possible(weights,days,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};