// Fenwick tree uses 1-based indexing
// User-facing indices are 0-based
// get sum of range [0, idx] (0-based)
// add delta to index idx (0-based)

template<class T>
struct Fenwick {
    int n;
    vector<T> a, bit;
 
    Fenwick(int _n = 0) { // build the BIT
        n = _n + 1;
        a = bit = vector<T>(n + 1);
    }
 
    void add(int idx, T delta) { // add a value to an index
        a[idx] += delta;
        for (int i = idx + 1; i <= n; i += i & -i) bit[i] += delta;
    }
 
    void set(int idx, T val) { add(idx, val - a[idx]); } // set a value to an index
 
    T query(int idx) { // get [0, idx]
        T sum = 0;
        for (int i = idx + 1; i >= 1; i -= i & -i) sum += bit[i];
        return sum;
    }
 
    T query(int l, int r) { return query(r) - query(l - 1); } // get [l, r]
}; 
 
