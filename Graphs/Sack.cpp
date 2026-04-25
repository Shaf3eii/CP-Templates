const int N = 1e6+5;
vector<int> adj[N];
int sz[N], bigChild[N], ans[N], depth[N];

void pre(int u, int p, int d) {
    sz[u] = 1;
    depth[u] = d;
    for (auto v : adj[u]) {
        if (v ^ p) {
            pre(v, u, d + 1);
            sz[u] += sz[v];
            if (bigChild[u] == 0 or sz[v] > sz[bigChild[u]]) bigChild[u] = v;
        }
    }
}

void upd(int u, int d) { 

}

void collect(int u, int p, int d) {
    upd(u, d);
    for (auto v : adj[u]) 
        if (v ^ p)
            collect(v, u, d);
}

void dfs(int u, int p, bool keep) {

    for (auto v : adj[u])
        if ((v ^ p) and (v != bigChild[u]))
            dfs(v, u, false);

    if (bigChild[u])
        dfs(bigChild[u], u, true);

    upd(u, +1);
    for (auto v : adj[u]) 
        if ((v ^ p) and (v != bigChild[u]))
            collect(v, u, +1);

    // answer

    if (!keep) {
        collect(u, p, -1);
        mxdep = -1;
    }
}