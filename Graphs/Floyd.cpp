 vector dp(n, vector<int> (n, 1e16));
for (int i = 0; i < n; ++i) dp[i][i] = 0;

for (int i = 0, u, v, c; i < m; ++i) {
    cin >> u >> v >> c;
    --u, --v;
    dp[u][v] = min(dp[u][v], c);
    dp[v][u] = min(dp[v][u], c);
}

for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);