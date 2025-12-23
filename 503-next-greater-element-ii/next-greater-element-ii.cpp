class Solution {
public:
    vector<int>nextgreater(vector<int>v){
        stack<int>st;
        int n=v.size();
        vector<int>ans(n,-1);
        for(int i=n-1;i>=0;i--){
            while(st.size()>0){
                if(st.top()<=v[i]){
                    st.pop();
                }else{
                    ans[i]=st.top();
                    break;
                }
            }
            st.push(v[i]);
        }
        return ans;
    }

    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>nums2;
        for(auto i:nums){
            nums2.push_back(i);
        }
        for(auto i:nums){
            nums2.push_back(i);
        }
        vector<int>ans=nextgreater(nums2);
        int n=nums.size();
        vector<int>f_ans(ans.begin(),ans.begin()+n);
        return f_ans;
    }
};