// Point Update Range Query
struct FenwickTreePURQ {
private:
    vector<long long> tree;
    int n;
public:
    FenwickTreePURQ(int size) {
        n = size;
        tree.assign(n, 0);
    }
 
    FenwickTreePURQ(vector<int>& arr) {
        n = arr.size();
        tree.assign(n, 0);
        for (int i = 0; i < n; i++) {
            update(i, arr[i]);
        }
    }
 
    // Add `delta` to element at idx (0-based)
    void update(int idx, long long delta) {
        while (idx < n) {
            tree[idx] ^= delta;
            idx |= (idx + 1);
        }
    }
    
    // Set the value at index idx to val (overwrites existing value)
    void PointUpdate(int idx, long long val) {
        int cur = rangeQuery(idx, idx + 1);
        update(idx, val - cur);
    }
 
    // Prefix sum [0..idx] (0-based)
    long long query(int idx) {
        long long sum = 0;
        while (idx >= 0) {
            sum ^= tree[idx];
            idx = (idx & (idx + 1)) - 1;
        }
        return sum;
    }
 
    // Range sum in [l, r) (0-based)
    long long rangeQuery(int l, int r) {
        return query(r - 1) ^ (l > 0 ? query(l - 1) : 0);
    }
 
    // Find the largest index such that prefix sum <= k
    int lowerBound(long long k) {
        int idx = -1;
        for (int bit = 1 << (31 - __builtin_clz(n)); bit; bit >>= 1) {
            int next = idx + bit;
            if (next < n && tree[next] <= k) {
                k -= tree[next];
                idx = next;
            }
        }
        return idx + 1;
    }
};


// Range Update Point Query
struct FenwickTreeRUPQ {
private:
    vector<long long> tree;
    int n;

    // Add `delta` starting from `idx` onward
    void internal_update(int idx, long long delta) {
        while (idx < n) {
            tree[idx] += delta;
            idx |= (idx + 1);
        }
    }

    // Prefix sum up to index `idx`
    long long prefix_sum(int idx) {
        long long res = 0;
        while (idx >= 0) {
            res += tree[idx];
            idx = (idx & (idx + 1)) - 1;
        }
        return res;
    }

public:
    FenwickTreeRUPQ(int size) {
        n = size;
        tree.assign(n, 0);
    }

    FenwickTreeRUPQ(vector<long long>& arr) {
        n = arr.size();
        tree.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            range_update(i, i + 1, arr[i]); 
        }
    }

    // Add `delta` to the range [l, r) — r not included
    void range_update(int l, int r, long long delta) {
        internal_update(l, delta);
        internal_update(r, -delta); 
    }

    // Get value at index `idx`
    long long point_query(int idx) {
        return prefix_sum(idx);
    }
};
