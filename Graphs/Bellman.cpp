void Yarab_Nfr7(int testcase) {
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    vector<int> dist(n, 1e18), par(n, -1);
    dist[0] = 0;
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w; --u, --v;
        edges.push_back({u, v, w});
    }

    for (int i = 0; i < n; ++i) {
        for (auto [u, v, w] : edges) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                par[v] = u;
            }
        }
    }

    int y = -1;
    for (auto [u, v, w] : edges)
        if (dist[u] + w < dist[v]) {
            y = v;
            par[v] = u;
            break;
        }

    if (y == -1) return void (cout << "NO");

    for (int i = 0; i < n; ++i) y = par[y];

    vector<int> ans;
    for (int u = y; ~u; u = par[u]) {
        ans.push_back(u);
        if (u == y and (int)ans.size() > 1) break;
    }
    reverse(begin(ans), end(ans));
    cout << "YES\n";
    for (auto u : ans) cout << u + 1 << ' ';
}
