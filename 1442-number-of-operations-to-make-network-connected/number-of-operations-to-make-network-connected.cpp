class Solution {
public:
    class DSU {
    public:
        vector<int> parent;
        vector<int> rank, size;

        DSU(int sz) {
            parent.resize(sz);
            rank.resize(sz);
            size.resize(sz);
            for (int i = 0; i < sz; i++) {
                parent[i] = i;
                rank[i] = 0;
                size[i] = 1;
            }
        }

        void print_parent() {

            for (int i = 0; i < parent.size(); i++) {
                cout << "{" << i << ":" << parent[i] << "}";
            }
            cout << endl;
        }

        int Find(int a) {
            if (a == parent[a])
                return a;
            return Find(parent[a]); // O(N)
        }

        void Union(int a, int b) {
            int leader_A = Find(a);
            int leader_B = Find(b);

            // parent[leader_A] = leader_B;

            // Union by Rank
            // if (rank[leader_A] < rank[leader_B])
            // {
            //     parent[leader_A] = leader_B;
            // }
            // else if (rank[leader_B] < rank[leader_A])
            // {
            //     parent[leader_B] = leader_A;
            // }
            // else
            // {
            //     // r[leader_A] == r[leader_B];
            //     parent[leader_A] = leader_B;
            //     rank[leader_A]++;

            //     // parent[leader_B] = leader_A;
            //     // rank[leader_A]++;
            // }

            if (size[leader_A] < size[leader_B]) {
                parent[leader_A] = leader_B;
                size[leader_B] += size[leader_A];
            } else {
                parent[leader_B] = leader_A;
                size[leader_A] += size[leader_B];
            }
        }
    };
    int makeConnected(int n, vector<vector<int>>& edges) {

        DSU* d = new DSU(n);

        int extra_edge = 0;

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (d->Find(u) == d->Find(v)) {
                extra_edge++;
            } else {
                d->Union(u, v);
            }
        }

        int component = 0;
        for (int i = 0; i < n; i++) {
            if (d->Find(i) == i) {
                component++;
            }
        }

        // total component
        // extra edge

        int edge_req = component - 1;
        if (extra_edge >= edge_req) {
            return edge_req;
        }

        return -1;
    }
};