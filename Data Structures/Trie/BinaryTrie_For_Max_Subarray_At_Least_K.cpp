struct BinaryTrie {
    struct Node {
        Node* child[2];
        int freq;

        Node() {
            child[0] = child[1] = nullptr;
            freq = 0;
        }
    };

    const int B = 31;
    Node* root;

    BinaryTrie() { root = new Node(); insert(0);}

    void insert(int x) {
        Node* cur = root;
        for (int b = B - 1; b >= 0; --b) {
            int bit = (x >> b) & 1;
            if (cur->child[bit] == nullptr) cur->child[bit] = new Node();
            cur = cur->child[bit];
            cur->freq++;
        }
    }

    void del_(int b, int x, Node* cur) {
        if (b == -1) return;
        int bit = (x >> b) & 1;
        del_(b - 1, x, cur->child[bit]);
        cur->child[bit]->freq--;
        if (cur->child[bit]->freq == 0) {
            delete cur->child[bit];
            cur->child[bit] = nullptr;
        }
    }

    void del(int x) {
        del_(B - 1, x, root);
    }

    int query(int x, int k) {
        Node* cur = root;
        int ans = 0;
        for (int b = B - 1; b >= 0; --b) {
            if (!cur) break;
            int xbit = (x >> b) & 1;
            int kbit = (k >> b) & 1;
            if (kbit == 0) {
                if (cur->child[xbit ^ 1] != nullptr)
                    ans += cur->child[xbit ^ 1]->freq;
                cur = cur->child[xbit];
            } else {
                cur = cur->child[xbit ^ 1];
            }
        }
        if (cur) ans += cur->freq;
        return ans;
    }
};


void Yarab_Nfr7(int testcase) {
    int n, k; cin >> n >> k;
    BinaryTrie trie;
    int pre = 0, ans = 0;
    // insert prefixes and count the number of subarrays that 
    // pre_r ^ pre_l >= k
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        pre ^= x;
        ans += trie.query(pre, k);
        trie.insert(pre);
    }
    cout << ans;
}
