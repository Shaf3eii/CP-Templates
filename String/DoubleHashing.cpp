constexpr int MOD1 = 1000000007, MOD2 = 1000000009, p1 = 133, p2 = 137;
vector<int> pow1, pow2;

void preCompute(int n) { // do not forget to call it !!
    pow1.resize(n + 1), pow2.resize(n + 1);
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pow1[i] = (pow1[i - 1] * p1) % MOD1;
        pow2[i] = (pow2[i - 1] * p2) % MOD2;
    }
}

struct Hash {
    vector<int> hash1, hash2;

    Hash () {}

    Hash(const string& s) {
        int n = s.size();
        hash1.resize(n + 1, 0), hash2.resize(n + 1, 0);
        for (int i = 0; i < n; ++i) hash1[i + 1] = ((hash1[i] * p1) % MOD1 + (s[i] - 'a' + 1)) % MOD1; // 1-based
        for (int i = 0; i < n; ++i) hash2[i + 1] = ((hash2[i] * p2) % MOD2 + (s[i] - 'a' + 1)) % MOD2; // 1-based
    }

    pair<int, int> getHash(int l, int r) {
        if (l > r) return {0, 0};
        l += 1;
        r += 1;
        int len = r - l + 1;

        int h1 = (hash1[r] - (hash1[l - 1] * 1ll * pow1[len]) % MOD1 + MOD1) % MOD1;
        int h2 = (hash2[r] - (hash2[l - 1] * 1ll * pow2[len]) % MOD2 + MOD2) % MOD2;

        return {h1, h2};
    }
};