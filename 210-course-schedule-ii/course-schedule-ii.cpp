class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n);

        for(auto edge : edges ){
            int course = edge[0];
            int preq = edge[1];
            adj[preq].push_back(course);
            indeg[course]++;
        }

        queue<int> q;
        for(int i =0 ; i < n; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(q.size()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto nei : adj[node]){
                indeg[nei]--;
                if(indeg[nei] == 0){
                    q.push(nei);
                }
            }
        }
        if(ans.size() != n) return {};
        return ans;
    }
};