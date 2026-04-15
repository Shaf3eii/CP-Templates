const int N = 2e5+5, LOG = 22;
int n;  
int c[N], dp[N], depth[N];
vector<int> adj[N];
int up[N][LOG], mn[N][LOG];
 
void dfs(int u, int p) {
    up[u][0] = p;
    mn[u][0] = dp[u];
 
    for (int v : adj[u]) 
        if (v ^ p) 
            depth[v] = depth[u] + 1, dfs(v, u);
}
 
void build() {
    dfs(1, 0);
 
    dp[0] = 0;
    for (int j = 1; j < LOG; ++j) 
        for (int v = 1; v <= n; ++v) {
            up[v][j] = up[up[v][j - 1]][j - 1];
            mn[v][j] = min(mn[v][j - 1], mn[up[v][j - 1]][j - 1]);
        }
 
}
 
int k_thAncestor(int u, int k) {
    for (int j = LOG - 1; j >= 0; --j) {
        if (k & (1ll << j)) {
            u = up[u][j];
            if (u == -1) break;
        }
    }
    return u;
}
 
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
 
    int k = depth[u] - depth[v];
    u = k_thAncestor(u, k);
 
    if (u == v) return u;
 
    for (int j = LOG - 1; j >= 0; --j) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
 
    return up[u][0];
}
 
int len(int u, int v) { // the long of the path from u to v
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}
 
int min_path(int u, int v) {
    int lc = lca(u, v);
    int ret = dp[lc];
 
    int k = depth[u] - depth[lc];
    for (int j = LOG - 1; j >= 0; --j) 
        if (k & (1ll << j)) {
            ret = min(ret, mn[u][j]);
            u = up[u][j];
        }
 
    k = depth[v] - depth[lc];
    for (int j = LOG - 1; j >= 0; --j) 
        if (k & (1ll << j)) {
            ret = min(ret, mn[v][j]);
            v = up[v][j];
        }
 
    return ret;
}
 
void Yarab_Nfr7(int testcase) {
    int q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        dp[i] = LLONG_MAX;
        for (int j = 0; j < LOG; ++j) {
            up[i][j] = 0;
            mn[i][j] = LLONG_MAX;
        }
    }
 
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    queue<int> bfs;
    for (int i = 1; i <= n; ++i) if (c[i]) bfs.push(i), dp[i] = 0;
 
    while (!bfs.empty()) {
        auto u = bfs.front(); bfs.pop();
 
        for (int v : adj[u]) {
            if (dp[v] > dp[u] + 1) {
                dp[v] = dp[u] + 1;
                bfs.push(v);
            }
        }
    }
 
    build();
}
