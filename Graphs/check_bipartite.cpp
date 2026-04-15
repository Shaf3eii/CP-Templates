vector<int> color(N);
 
bool dfs_check_bipartite(int u) {
    bool can = true;
    for (auto v: adj[u]) {
        if (!color[v]) {
            color[v] = 3 - color[u];
            can &= dfs_check_bipartite(v);
        } else if (color[v] == color[u]) {
            return false;
        }
    }
    return can;
}
 
bool bfs_check_bipartite(int st) {
    queue<int> q;
    q.push(st);
    color[st] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (auto v: adj[u]) {
            if (!color[v]) {
                color[v] = 3 - color[u];
                q.push(v);
            } else if (color[u] == color[v]) {
                return false;
            }
        }
    }
    return true;
}
