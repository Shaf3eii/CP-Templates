struct Node {
    int sum, lazy = 0;
    bool isLazy = false;

    Node() : sum(0) { }
    Node(int x) : sum(x) {}
    void updateNode(int x, int lx, int rx) {
        sum += x * (rx - lx);
        lazy += x;
        isLazy = true;
    }
};


struct SagaraWithLazy {
#define leftChild  (node * 2 + 1)
#define rightChild (node * 2 + 2)
#define mid        ((lx + rx >> 1))

    int treeSize;
    vector<Node> segData;

    void build(int node, int lx, int rx, vector<int>& arr) {
        if (rx - lx == 1) {
            if (lx < (int)arr.size())
                segData[node] = Node(arr[lx]);
            return;
        }

        build(leftChild, lx, mid, arr);
        build(rightChild, mid, rx, arr);

        segData[node] = merge(segData[leftChild], segData[rightChild]);
    }

    Node merge(Node& L, Node& R) {
        Node res = Node();
        res.sum = L.sum + R.sum;
        return res;
    }


    void propagate(int node, int lx, int rx) {
        if (rx - lx == 1 or !segData[node].isLazy) return;

        segData[leftChild].updateNode(segData[node].lazy, lx, mid);
        segData[rightChild].updateNode(segData[node].lazy, mid, rx);

        segData[node].isLazy = segData[node].lazy = 0;
    }

    void update(int l, int r, int x, int node, int lx, int rx) {
        propagate(node, lx, rx);

        if (l >= rx or lx >= r) return;
        if (l <= lx and rx <= r) {
            segData[node].updateNode(x, lx, rx);
            return;
        }

        update(l, r, x, leftChild, lx, mid);
        update(l, r, x, rightChild, mid, rx);

        segData[node] = merge(segData[leftChild], segData[rightChild]);
    }


    Node query(int l, int r, int node, int lx, int rx) {
        propagate(node, lx, rx);

        if (l >= rx or lx >= r) return Node();
        if (l <= lx and rx <= r) {
            return segData[node];
        }

        Node left = query(l, r, leftChild, lx, mid);
        Node right = query(l, r, rightChild, mid, rx);

        return merge(left, right);
    }

public:
    SagaraWithLazy(int n, vector<int>& arr) {
        treeSize = 1;
        while (treeSize < n) treeSize <<= 1;
        segData = vector<Node>(treeSize << 1);
        build(0, 0, treeSize, arr);
    }

    void update(int l, int r, int x) {
        update(l, r, x, 0, 0, treeSize);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, treeSize).sum;
    }
};
