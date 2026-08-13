class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // // brute form O(n^2)
        // int n=nums.size();
        // vector<int>ans;
        // unordered_map<int,int>mp;
        // for(auto x:nums){
        //     mp[x]++;
        // }
        // while(k--){
        //     int a=0;
        //     int mx=INT_MIN;
        //     for(auto x:mp){
        //         if(a<x.second){
        //             mx=x.first;
        //             a=x.second;
        //         }
        //     }
        //     ans.push_back(mx);
        //     mp.erase(mx);
        // }
        // return ans;


        // // optimal O(nlogn)
        // unordered_map<int,int> freq;
        // for(int x : nums){
        //     freq[x]++;
        // }
        // priority_queue<pair<int,int>> pq; 
        // for(auto &p : freq){
        //     pq.push({p.second, p.first});
        // }
        // vector<int> ans;
        // while(k--){
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        // return ans;

        // Optimal Tc= O(n),  Sc=O(n)
        vector<int>ans;
        vector<int>freq(200001,0);
        int a=100000;
        for(int x:nums){
            x+=a;
            freq[x]++;
        }
        vector<pair<int, int>>freq2;
        for(int i=0;i<freq.size();i++){
            if(freq[i]>0)
                freq2.push_back({freq[i],i-a});
        }
        sort(freq2.begin(),freq2.end(),greater<pair<int,int>>());
        for(int i=0;i<k;i++){
            ans.push_back(freq2[i].second);
        }
        return ans;


    }
};
