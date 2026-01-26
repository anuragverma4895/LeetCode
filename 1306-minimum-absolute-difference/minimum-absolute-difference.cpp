class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<int>temp;
        for(int i=1;i<n;i++){
            temp.push_back(abs(arr[i-1]-arr[i]));
        }
        int mn=*min_element(temp.begin(),temp.end());
        int x=INT_MAX;
        vector<vector<int>>ans;
        for(int i=1;i<n;i++){
            int x=abs(arr[i-1]-arr[i]);
            if(mn==x){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }

};