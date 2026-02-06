class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        unordered_map<int,int>freq;
        for(int x:a){
            freq[x]++;
        } 
        vector<int>ans;
        for(int x:b){
            if(freq[x]>0){
                freq[x]--;
                ans.push_back(x);
            }
        }
        return ans;
    }
};