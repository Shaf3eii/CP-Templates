
int SQ;
struct Query {
    int l, r, idx;

    bool operator<(Query &other) {
        if (l / SQ != other.l / SQ) return l / SQ < other.l / SQ;
        return r < other.r;
    }
};

struct DSU {
    vector<int> leader, rank;
    int comp;
    stack<array<int, 5>> history;
    DSU(int n) {
        leader.resize(n + 1);
        rank.resize(n + 1);
        comp = n;
        for (int i = 0; i <= n; ++i) {
            leader[i] = i;
            rank[i] = 1;
        }
    }

    int find_leader(int u) {
        return leader[u] == u ? u : find_leader(leader[u]);
    }

    bool is_same_set(int u, int v) {
        return find_leader(u) == find_leader(v);
    }

    bool unite(int u, int v) {
        array<int, 5> h = {-1, -1, -1, -1, -1};

        u = find_leader(u), v = find_leader(v);
        if (u == v) return false;

        if (rank[u] > rank[v]) swap(u, v);

        h = {leader[u], u, rank[v], v, comp};
        history.push(h);

        comp--;
        leader[u] = v;
        rank[v] += rank[u];
        return true;
    }
    
    void persist() { history.push({-5, -5, -5, -5, -5}); }

    void rollback() {
        while (history.top()[0] != -5) {
            leader[history.top()[1]] = history.top()[0];
            rank[history.top()[3]] = history.top()[2];
            comp = history.top()[4];
            history.pop();
        }
        history.pop();
    }
};

void Yarab_Nfr7(int testcase) {
    int n, m; cin >> n >> m;
    vector<array<int, 2>> edges(m + 1);
    for (int i = 1; i <= m; ++i) cin >> edges[i][0] >> edges[i][1];

    SQ = sqrt(m + .0) + 1;

    int q; cin >> q;
    vector<Query> blk[SQ];
    for (int i = 0, l, r; i < q; ++i) {
        cin >> l >> r;
        blk[l/SQ].push_back({l, r, i});
    }

    vector<int> ans(q);
    for (int i = 0; i < SQ; ++i) {
        sort(begin(blk[i]), end(blk[i]));
        DSU dsu(n);
        int curR = (i + 1) * SQ;

        for (auto [lq, rq, idx] : blk[i]) {
            int l = lq, r = rq;

            if (r < (i + 1) * SQ) {
                dsu.persist();

                while (l <= r) {
                    dsu.unite(edges[l][0], edges[l][1]);
                    l++;
                }

                ans[idx] = dsu.comp;
                dsu.rollback();
                continue;
            }

            while (curR <= r) {
                dsu.unite(edges[curR][0], edges[curR][1]);
                curR++;
            }

            dsu.persist();
            int curL = (i + 1) * SQ;
            while (l <= curL) {
                dsu.unite(edges[curL][0], edges[curL][1]);
                curL--;
            }

            ans[idx] = dsu.comp;
            dsu.rollback();
        }
    }

    for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
}

