class Solution {
public:
    vector<int>nextSmaller(const vector<int>&v){
        int n=v.size();
        vector<int>ans(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(st.size()>0){
                if(v[st.top()]>=v[i]){
                    st.pop();
                }else{
                    ans[i]=st.top();
                    break;
                }
            }
            st.push(i);
        }
        return ans;
    }
    vector<int>prevSmaller(vector<int>&v){
        int n=v.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(st.size()>0){
                if(v[st.top()]>=v[i]){
                    st.pop();
                }else{
                    ans[i]=st.top();
                    break;
                }
            }
            st.push(i);
        }
        return ans;
    }
    // TC=O(n) and SC=O(N)
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next_smaller=nextSmaller(heights);
        vector<int>prev_smaller=prevSmaller(heights);
        int ans=0;
        for(int i=0;i<n;i++){
            int right_boun=next_smaller[i];
            int left_boun=prev_smaller[i];
            int curr=heights[i]*(right_boun-left_boun-1);
            ans=max(ans,curr);
        }
        return ans;
    }
};