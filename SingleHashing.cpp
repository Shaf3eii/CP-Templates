mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
T rand(T l, T r) {
    return uniform_int_distribution<T>(l, r)(rng);
}

struct Hash {
private:
    const int mod1 = 1e9 + 7;
    int base1;
    int n;
    vector<int> pw1, hash1;

    vector<int> hash(string &s, vector<int> &pw, const int mod) {
        vector<int> res(n);
        res[0] = (s[0] - 'a' + 1);
        for (int i = 1; i < n; i++) {
            res[i] = 1LL * (s[i] - 'a' + 1) * pw[i] % mod + res[i - 1];
            if (res[i] >= mod) res[i] -= mod;
        }
        return res;
    }
    
    int query(vector<int> &hash, vector<int> &pw, int l, int r, const int mod) {
        int res = hash[r];
        if (l > 0) res -= hash[l - 1];
        if (res < 0) res += mod;
        res = 1LL * res * pw[n - l] % mod;
        return res;
    }
public:
    Hash(string &s) {
        n = s.size();
        base1 = rand((int) 1e6, (int) 1e8);
        pw1.resize(n + 1);
        pw1[0] = 1;
        for (int i = 1; i <= n; i++) {
            pw1[i] = 1LL * base1 * pw1[i - 1] % mod1;
        }
        hash1 = hash(s, pw1, mod1);
    }
    
    long long get_hash(int l, int r) {
        return 1LL * query(hash1, pw1, l, r, mod1);
    }
};
