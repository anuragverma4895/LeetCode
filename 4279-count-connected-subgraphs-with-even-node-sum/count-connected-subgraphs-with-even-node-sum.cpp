class Solution {
public:
    int evenSumSubgraphs(vector<int>& n, vector<vector<int>>& e) {
        int s=n.size();
        vector<vector<int>>g(s);
        for(auto& i:e){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        int c=0;
        for(int m=1;m<(1<<s);++m){
            int v=0;
            vector<int>l;
            for(int i=0;i<s;i++){
                if((m>>i)&1){
                    v+=n[i];
                    l.push_back(i);
                }
            }
            if(v%2!=0) continue;
            queue<int>q;
            q.push(l[0]);
            int w=0;
            w |=(1<<l[0]);
            int k=0;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                k++;
                for(int x:g[u]){
                    if(((m>>x)&1) && !((w>>x)&1)){
                        w|=(1<<x);
                        q.push(x);
                    }
                }
            }
            if(k==l.size()){
                c++;
            }
        }
        return c;
    }
};