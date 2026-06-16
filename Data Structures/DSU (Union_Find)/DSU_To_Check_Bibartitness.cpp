 
struct DSU {
    vector<int> leader, dist;
 
    DSU(int n) {
        leader.resize(n + 1);
        dist.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            leader[i] = i;
            dist[i] = 0;
        }
    }
 
    int find_leader(int u) {
        if (u == leader[u]) return u;
        int par = leader[u];
        int root = find_leader(par);
        leader[u] = root;
        dist[u] += dist[par];
        dist[u] %= 2;
        return root;
    }
 
    bool is_same_set(int u, int v) {
        return find_leader(u) == find_leader(v);
    }
 
    bool unite(int u, int v) {
        int ru = find_leader(u), rv = find_leader(v);
        if (ru == rv) return false;
        leader[ru] = rv;
        dist[ru] = (1 + dist[u] + dist[v]) % 2;
        return true;
    }
 
    int getDistance(int u) {
        find_leader(u);
        return dist[u];
    }
};