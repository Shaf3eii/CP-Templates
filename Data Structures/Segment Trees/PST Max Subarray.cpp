struct Node {
    Node *left{}, *right{};
    int sum{}, ans{}, pre{}, suf{}, len{};

    Node() {
        left = right = nullptr;
        sum = pre = suf = ans = len = 0;    
    }
    Node(int val) : sum(val), pre(val), ans(val), suf(val), len(1) {}
    Node(Node *l, Node *r) {
        left = l;
        right = r;

        sum = left->sum + right->sum;
        pre = left->pre;
        if (left->len == left->pre) pre += right->pre;

        suf = right->suf;
        if (right->len == right->suf) suf += left->suf;
        
        len = left->len + right->len;

        ans = max({right->ans, left->ans, right->pre + left->suf});
    }
};

struct PST {
    int n;
    vector<Node*> roots;

    PST() {}
    PST(int n, int m) : n(n), roots(m) { }

    void init(int n, int m) {
        this->n = n;
        roots = vector<Node*> (m);
    }

    Node* build(int l, int r) {
        if (l == r) return new Node(0);
        int mid = (l + r) / 2;
        Node* left = build(l, mid);
        Node* right = build(mid + 1, r);
        return new Node(left, right);
    }

    Node merge(Node l, Node r) {
        Node ret;
        ret.sum = l.sum + r.sum;
        ret.pre = l.pre;
        if (l.pre == l.len) ret.pre += r.pre;
        ret.suf = r.suf;
        if (r.suf == r.len) ret.suf += l.suf;
        ret.len = r.len + l.len;
        ret.ans = max({l.ans, r.ans, l.suf + r.pre});
        return ret;
    }

    Node* update(Node* node, int l, int r, int idx, int val) {
        if (l == r) return new Node(node->sum + val); // if u accumulate on the node don't change this, if u set a new value to the node remove the old sum
        int mid = (l + r) / 2;
        if (idx <= mid)
            return new Node(update(node->left, l, mid, idx, val), node->right);
        return new Node(node->left, update(node->right, mid + 1, r, idx, val));
    }

    Node* update(int v, int idx, int val) { return update(roots[v], 0, n - 1, idx, val); }

    Node query(Node* node, int l, int r, int ql, int qr) {
        if (l > qr or r < ql) return {};
        if (l >= ql and qr >= r) return *node;
        int mid = (l + r) / 2;
        return merge(query(node->left, l, mid, ql, qr), query(node->right, mid + 1, r, ql, qr));
    }

    Node query(int v, int l, int r) { return query(roots[v], 0, n - 1, l, r); }

    int k_thSmallest(Node* u, Node* v, Node* lca, Node* plca, int k, int l, int r) {
        if (l == r) return l;

        int mid = (l + r) / 2;
        int cnt = u->left->sum + v->left->sum - lca->left->sum - plca->left->sum;

        if (cnt >= k) return k_thSmallest(u->left, v->left, lca->left, plca->left, k, l, mid);
        return k_thSmallest(u->right, v->right, lca->right, plca->right, k - cnt, mid + 1, r);
    }

    int k_thSmallest(int v, int u, int lca, int plca, int k) { return k_thSmallest(roots[u], roots[v], roots[lca], roots[plca], k, 0, n - 1); }

    int k_thOne(Node* u, int l, int r, int k) {
        if (!u or u->sum <= k) return r;
        if (l == r) return l - 1;

        int mid = (l + r) / 2;
        if (u->left->sum > k) return k_thOne(u->left, l, mid, k);
        return k_thOne(u->right, mid + 1, r, k - u->left->sum);
    }

    int k_thOne(int u, int k) { return k_thOne(roots[u], 0, n - 1, k); }
};