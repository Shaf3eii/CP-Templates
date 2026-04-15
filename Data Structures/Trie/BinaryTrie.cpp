struct BinaryTrie {
    struct Node {
        Node* child[2];
        int freq[2];
        Node() {
            child[0] = child[1] = nullptr;
            freq[0] = freq[1] = 0;
        }
    };
    Node* root;
    const int B = 30;
    BinaryTrie() {
        root = new Node();
        insert(0);
    }
    void insert(int x) {
        Node* cur = root;
        for (int i = B; ~i; --i) {
            bool idx = (x >> i) & 1;
            if (cur->child[idx] == nullptr) {
                cur->child[idx] = new Node();
            }
            cur->freq[idx]++;
            cur = cur->child[idx];
        }
    }
    void del(int x, int b, Node* cur) {
        if (b == -1) return;
        bool idx = (x >> b) & 1;
        del(x, b - 1, cur->child[idx]);
        cur->freq[idx]--;
        if (cur->freq[idx] == 0) {
            delete cur->child[idx];
            cur->child[idx] = nullptr;
        }
    }
    void delete_(int x) {
        del(x, B, root);
    }

    bool search(int x) {
        Node* cur = root;
        for (int i = B; ~i; --i) {
            bool idx = (x >> i) & 1;
            if (cur->child[idx] == nullptr) {
                return false;
            }
            cur = cur->child[idx];
        }
        return true;
    }

    int query(int x) {
        Node* cur = root;
        int ret = 0;
        for (int i = B; ~i; --i) {
            bool idx = (x >> i) & 1;
            if (cur->child[idx ^ 1] != nullptr) {
                cur = cur->child[idx ^ 1];
                ret |= (1 << i);
            } else {
                cur = cur->child[idx];
            }
        }
        return ret;
    }
};
