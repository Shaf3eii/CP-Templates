struct Trie {
    struct Node {
        int prefix, end, sz;
        int child[26];
        Node() {
            prefix = end = sz = 0;
            memset(child, -1, sizeof(child));
        }
    };
    vector<Node> root;
    Trie() { root.resize(1); }
    void insert(string &s) {
        int v = 0, cnt = 0;
        for (auto it : s) {
            int idx = it - 'a';
            if (root[v].child[idx] == -1) {
                root[v].child[idx] = root.size();
                root.emplace_back();
            }

            v = root[v].child[idx];
            cnt++;
            root[v].prefix++;
        }
        root[v].end++;
    }

};