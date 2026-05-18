struct Aho {
    int N, P, A, B;
    vector<vector<int>> nxt, out;
    vector<int> link, out_link;

    Aho(int A, int B): N(0), P(0), A(A), B(B) {node();}
    int node() {
        nxt.emplace_back(A, 0);
        link.emplace_back(0);
        out_link.emplace_back(0);
        out.emplace_back(0);
        return N++;
    }

    int get (char c) {return c - B;}

    int insert(const string &p) {
        int u = 0;
        for (auto &c: p) {
            if (!nxt[u][get(c)]) nxt[u][get(c)] = node();
            u = nxt[u][get(c)];
        }

        out[u].push_back(P);
        return P++;
    }

    void build() {
        queue <int> q;
        for (q.push(0); !q.empty();) {
            int u = q.front(); q.pop();
            for (int c = 0; c < A; ++c) {
                int v = nxt[u][c];
                if (!v) nxt[u][c] = nxt[link[u]][c];
                else {
                    link[v] = u ? nxt[link[u]][c] : 0;
                    out_link[v] = out[link[v]].empty() ? out_link[link[v]] : link[v];
                    q.push(v);
                }
            }
        }
    }

    int advance (int u, char c) {
        while (u && !nxt[u][get(c)]) u = link[u];
        u = nxt[u][get(c)];
        return u;
    }
};
