struct DSU {
    vector<int> leader, rank;

    DSU(int n) {
        leader.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            leader[i] = i;
            rank[i] = 1;
        }
    }

    int find_leader(int u) {
        return leader[u] = leader[u] == u ? u : find_leader(leader[u]);
    }

    bool is_same_set(int u, int v) {
        return find_leader(u) == find_leader(v);
    }

    bool unite(int u, int v) {
        u = find_leader(u), v = find_leader(v);
        if (u == v) return false;

        if (rank[u] > rank[v]) swap(u, v);

        leader[u] = v;
        rank[v] += rank[u];
        return true;
    }
};
