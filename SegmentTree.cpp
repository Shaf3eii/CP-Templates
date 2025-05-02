struct Node {
    int sum;
 
    Node() {
        sum = 0;
    }
 
    Node(int val) {
        sum = val;
    }
 
    void change(int val) {
        sum = val;
    }
};
 
struct SegmentTree {
    int treeSize;
    vector<Node> segData;
 
    SegmentTree(int n) {
        treeSize = 1;
        while (treeSize < n) {treeSize *= 2;}
        segData = vector<Node>(2 * treeSize);
    }
 
    Node merge(Node& l, Node& r) {
        Node ans = Node();
        ans.sum = l.sum + r.sum;
        return ans;
    }
 
    void set(int idx, int val, int node, int l, int r) {
        if (r - l == 1) {
            segData[node] = val;
            return;
        }
 
        int mid = (l + r) / 2;
 
        if (idx < mid) {
            set(idx, val, node * 2 + 1, l, mid);
        } else {
            set(idx, val, node * 2 + 2, mid, r);
        }
 
        segData[node] = merge(segData[node * 2 + 1], segData[node * 2 + 2]);
    }
    void set(int idx, int val) {
        set(idx, val, 0, 0, treeSize);
    }
 
    Node get(int l, int r, int node, int lf, int ri) {
        if (lf >= l and ri <= r) {
            return segData[node];
        }
        if (lf >= r or ri <= l) {
            return Node();
        }
 
        int mid = (lf + ri) / 2;
        Node left = get(l, r, node * 2 + 1, lf, mid);
        Node right = get(l, r, node * 2 + 2, mid, ri);
 
        return merge(left, right);
    }
 
    int get(int l, int r) {
        return get(l, r, 0, 0, treeSize).sum;
    }
};
