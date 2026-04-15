int SQ;
struct Query {
    int l, r, idx;

    bool operator<(Query &other) {
        if (l / SQ != other.l / SQ) return l / SQ < other.l / SQ;
        return (l / SQ & 1 ? r < other.r : r > other.r);
    }
};

// remember ya 3l2 enk da3eef
void Solve(int testcase) {

    SQ = sqrt(n + .0) + 1;

    vector<Query> qu(q);
    for (int i = 0, l, r; i < q; ++i) {
        cin >> l >> r;
        qu[i] = {l, r, i};
    }

    sort(begin(qu), end(qu));
    int res = 0;

    auto add = [&](int idx) {

    };

    auto del = [&](int idx) {

    };

    auto get = [&]() {
        return res;
    };

    vector<int> ans(q);
    int l = 0, r = -1;
    for (auto [lq, rq, idx] : qu) {
        while (l > lq) add(--l);
        while (r < rq) add(++r);
        while (l < lq) del(l++);
        while (r > rq) del(r--);
        ans[idx] = get();
    }

    for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
}
