class Solution {
public:

    // void bfs(vector<vector<int>>&adj, int node, vector<int>&vis){
    //     queue<int>q;
    //     q.push(node);
    //     while(q.size()){
    //         int curr=q.front();
    //         q.pop();
    //         if(vis[curr]==1) continue;
    //         vis[curr]=1;
    //         for(int neig=0;neig<adj.size();neig++){
    //             if(adj[curr][neig]==1 && vis[neig]==0){
    //                 q.push(neig);
    //             }
    //         }

    //     }
    // }

    void dfs(vector<vector<int>>&adj, int node, vector<int>&vis){
        vis[node]=1;
        for(int i=0;i<adj.size();i++){
            if(adj[node][i]==1 && vis[i]==0){
                dfs(adj,i,vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(isConnected, i, vis);
                count++;
            }
        }
        return count;
    }
};