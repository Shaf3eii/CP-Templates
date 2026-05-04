struct SuffixArray {

    vector<int> sa, lcp, rank, logs;
    vector<vector<int>> sparse;
    string s;
    int n;

    SuffixArray(string text) : s(text) {
        s.push_back(' ');
        n = (int)s.size();
        constructSuffixArray();
        contructLCP();
        constructSparse();
    }

    void countSort(vector<int>& p, vector<int>& c) {
        int sz = p.size();
        vector<int> cnt(sz), pos(sz), np(sz);
        for (int i = 0; i < sz; i++) cnt[c[p[i]]]++;
        for (int i = 1; i < sz; i++) cnt[i] += cnt[i - 1];
        for (int i = sz - 1; i >= 0; i--) np[--cnt[c[p[i]]]] = p[i];
        p.swap(np);
    }

    void constructSuffixArray() {
        const int alphabet = 256;
        vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
        for (int i = 0; i < n; ++i) cnt[s[i]]++;
        for (int i = 1; i < alphabet; ++i) cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; ++i) p[--cnt[s[i]]] = i;
        c[p[0]] = 0;
        int classes = 1;
        for (int i = 1; i < n; ++i) {
            classes += s[p[i]] != s[p[i - 1]];
            c[p[i]] = classes - 1;
        }

        vector<int> nc(n);
        for (int k = 0; (1 << k) < n; ++k) {
            for (int i = 0; i < n; ++i) {
                p[i] = ((p[i] - (1 << k) + n)) % n;
            }
            countSort(p, c);
            nc[p[0]] = 0;
            classes = 1;
            for (int i = 1; i < n; ++i) {
                pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << k)) % n]};
                pair<int, int> pre = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
                classes += cur != pre;
                nc[p[i]] = classes - 1;
            }
            c.swap(nc);
        }
        sa = p;
    }

    void contructLCP() {
        rank.resize(n);
        lcp.resize(n - 1);
        for (int i = 0; i < n; ++i) rank[sa[i]] = i;
        int k = 0; // common so far
        for (int i = 0; i < n; ++i) {
            int idx = rank[i];
            if (idx == n - 1) {
                k = 0;
                continue;
            }
            int j = sa[idx + 1];
            while ((i + k) < n and s[i + k] == s[j + k]) k++;
            lcp[idx] = k;
            if (k) k--;
        }
    }

    void constructSparse() {
        logs = vector<int> (n + 5, 0);
        for (int i = 2; i < n + 2; ++i) logs[i] = logs[i / 2] + 1;

        sparse = vector<vector<int>> (n, vector<int> (22, INT_MAX));

        for (int i = 0; i < n - 1; ++i) sparse[i][0] = lcp[i];

        for (int j = 1; j <= logs[n]; ++j) {
            for (int i = 0; (i + (1ll << j)) <= n; ++i) {
                sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1ll << (j - 1))][j - 1]);
            }
        }
    }

    int queryLcp(int l, int r) {
        if (l == r) return n - sa[l];
        if (l > r) swap(l, r);
        int len = logs[r - l];
        return min(sparse[l][len], sparse[r - (1ll << len)][len]);
    }

    int search(string& t) {
        int l = 0, r = n - 1, m = (int)t.size(), ret = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (s.compare(sa[mid], m, t) >= 0) { // t is smaller than s[i...n - 1];
                ret = mid;
                r = mid - 1;
            } else { // t is bigger than s[i...n - 1];
                l = mid + 1;
            }
        }
        return ret;
    }

    int countSubStrings(string& t) {
        int m = (int)t.size();

        auto lower = [&]() {
            int l = 0, r = n - 1, ret = n;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if ((s.compare(sa[mid], m, t) >= 0)) {
                    ret = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            return ret;
        };

        auto upper = [&]() {
            int l = 0, r = n - 1, ret = n;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if ((s.compare(sa[mid], m, t) > 0)) {
                    ret = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            return ret;
        };

        return upper() - lower();
    }

    string longestCommonSubstring(int sz) {
        int l = 0, idx = 0;
        for (int i = 0; i + 1 < (int)sa.size(); ++i) {
            int cur = sa[i];
            int nxt = sa[i + 1];

            bool diff = (cur < sz != nxt < sz);
            if (diff) {
                if (l < lcp[i]) {
                    l = lcp[i];
                    idx = cur;
                }
            }
        }
        return s.substr(idx, l);
    }

    int compareTwoSubStrings(int l1, int r1, int l2, int r2) { // return 1 -> first is smaller, return 2 -> second is smaller, return 0 -> equal
        int lcPrefix = min({queryLcp(rank[l1], rank[l2]), r1 - l1 + 1, r2 - l2 + 1});
        if (lcPrefix == (r1 - l1 + 1) and lcPrefix == (r2 - l2 + 1)) return 0; // longest common prefix is equal
        if (lcPrefix == (r1 - l1 + 1)) return 1; // the first string is a prefix of the second string
        if (lcPrefix == (r2 - l2 + 1)) return 2; // the second string is a prefix of the first string

        int a = s[l1 + lcPrefix], b = s[l2 + lcPrefix];
        if (a < b) return 1;
        else if (b < a) return 2;
        else return 0;
    }
};