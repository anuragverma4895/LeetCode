class Solution {
public:
    long long countGoodSubarrays(vector<int>& ns) {
        int n=ns.size();
        long long an=0;
        unordered_map<int,int>ls;
        vector<pair<int,int>>v;
        for(int ri=0;ri<n;ri++){
            int x=ns[ri];
            ls[x]=ri;
            vector<pair<int,int>>nv;
            nv.push_back({x,ri});
            for(auto&p:v){
                int no=p.first | x;
                if(no!=nv.back().first){
                    nv.push_back({no,p.second});
                    // nv.back().second=p.second;
                // }else{
                }
            }
            v=nv;
            for(int i=0;i<v.size();i++){
                int co=v[i].first;
                int st=v[i].second;
                int lb=(i+1<v.size())?v[i+1].second+1:0;
                // int l2=(i+1<v.size())?v[i+1].second:-1;
                // if(ls.count(co) && ls[co]>=l1){
                //     int st=l1;
                //     int en=(l2==-1)? -1 :l2+1;
                    // int lb=(l2==-1)?0:l2+1;
                if(ls.count(co)&& ls[co]>=lb){
                    int valid=min(st,ls[co]);
                    if(valid>=lb){
                        an+=(valid-lb+1);
                    }
                }
            }
        }
        return an;
    }
};