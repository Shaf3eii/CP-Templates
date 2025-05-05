struct SegmentTree {
#define LeftChild  (node * 2 + 1)
#define RightChild (node * 2 + 2)
#define mid        (l + r >> 1)
 
private:
    struct Node {
        int sum;
        Node() : sum(0) {}
        Node(int x) : sum(x) {}
        void change(int x) {
            sum = x;
        }
    };
 
    vector<Node> segData;
    int tree_size;
 
    void build(vector<int>& arr, int node, int l, int r) {
        if (r - l == 1) {
            if (l < arr.size()) {
                segData[node] = Node(arr[l]);
            }
            return;
        }
 
        build(arr, LeftChild, l, mid);
        build(arr, RightChild, mid, r);
 
        segData[node] = merge(segData[LeftChild], segData[RightChild]);
    }
 
    Node merge(Node& l, Node& r) {
        Node ans = Node();
        ans.sum = l.sum + r.sum;
        return ans;
    }
 
    void update(int idx, int val, int node, int l, int r) {
        if (r - l == 1) {
            segData[node].change(val);
            return;
        }
 
        if (idx < mid) {
            update(idx, val, LeftChild, l, mid);
        } else {
            update(idx, val, RightChild, mid, r);
        }
 
        segData[node] = merge(segData[LeftChild], segData[RightChild]);
    }
 
    Node query(int left, int right, int node, int l, int r) {
        if (l >= left and r <= right) return segData[node];
        if (l >= right or left >= r) return Node();
 
        Node L = query(left, right, LeftChild, l, mid);
        Node R = query(left, right, RightChild, mid, r);
 
        return merge(L, R);
    }
 
public:
    SegmentTree(int n, vector<int>& arr) {
        tree_size = 1;
        while (tree_size < n) tree_size <<= 1;
        segData = vector<Node>(2 * tree_size);
        build(arr, 0, 0, tree_size);
    }
 
    void update(int idx, int val) {
        update(idx, val, 0, 0, tree_size);
    }
 
    int query(int left, int right) {
        return query(left, right, 0, 0, tree_size).sum;
    }
 
#undef LeftChild
#undef RightChild
#undef mid
};
