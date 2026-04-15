int n, timer = 0;
vector<vector<int>> adj;
vector<int> val, in, out;

void dfs(int u, int p = 0) {
    in[u] = timer++;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    out[u] = timer;
}
