class Solution {
public:
    
    vector<vector<int>>ans;
    vector<int>path;
    void dfs(int u, vector<vector<int>>&graph){
        path.push_back(u);
        if(u==graph.size()-1){
            ans.push_back(path);
            path.pop_back();
            return;
        }
        for(auto i :graph[u]){
            dfs(i,graph);
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(0,graph);
        return ans;
    }
};