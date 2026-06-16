const int INF = 1e12;

struct Edge {
    int u{}, v{}, cap{}, flow{};

    Edge(int u, int v, int cap) : u(u), v(v), cap(cap) {}

    int rem() { return cap - flow; }
};

struct EdmondKarp {
    int n, s, t;
    vector<vector<int>> adj;
    vector<Edge> edges;
    vector<int> par;

    EdmondKarp(int n, int s, int t) : n(n), s(s), t(t) {
        adj.assign(n + 1, {});
    }

    void addEdge(int u, int v, int w = INF, int undir = 0) {
        adj[u].push_back((int)edges.size());
        edges.push_back(Edge(u, v, 1));
        adj[v].push_back((int)edges.size());
        edges.push_back(Edge(v, u, 1));
    }

    int maxFlow() {
        int ret = 0, flow = 0;
        while (flow = bfs()) {
            ret += flow;
            int u = t;
            while (u != s) {
                edges[par[u]].flow += flow;
                edges[par[u] ^ 1].flow -= flow;
                u = edges[par[u]].u;
            }
        }
        return ret;
    }

    int bfs() {
        par.assign(n + 1, -1);
        par[s] = -2;
        queue<pair<int, int>> q;
        q.push({s, INF});

        while (!q.empty()) {
            auto [cur, flow] = q.front(); q.pop();

            if (cur == t) return flow;

            for (auto nxt : adj[cur]) {
                auto [u, v, cap, f] = edges[nxt];
                if (~par[v] or !edges[nxt].rem()) continue;
                q.push({v, min(flow, edges[nxt].rem())});
                par[v] = nxt;
            }
        }

        return 0;
    }

    vector<pair<int, int>> minCutEdges() {
        vector vis(n + 1, false);
        vis[s] = true;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            auto cur = q.front(); q.pop();

            for (auto nxt : adj[cur]) {
                auto [u, v, cap, f] = edges[nxt];

                if (!vis[v] and edges[nxt].rem()) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }

        vector<pair<int, int>> ans;
        for (auto i : edges) {
            auto [u, v, cap, flow] = i;
            if (vis[u] and !vis[v])
                ans.push_back({u, v});
        }

        return ans;
    }

};
