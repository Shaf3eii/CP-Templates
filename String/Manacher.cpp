struct Manacher {
private:
    vector<int> manacher_odd(const string& s) {
        int n = s.size();
        string temp = "$" + s + "^";
        vector<int> p(n + 2, 0);
        int l = 0, r = 1;

        for(int i = 1; i <= n; i++) {
            if(i <= r) {
                p[i] = min(r - i, p[l + (r - i)]);
            }

            while(temp[i - p[i]] == temp[i + p[i]]) {
                p[i]++;
            }

            if(i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
        return vector<int>(begin(p) + 1, end(p) - 1);
    }

public:
    vector<int> d;

    Manacher(const string& s) {
        string t;
        t.reserve(s.size() * 2 + 1);
        for(char c : s) {
            t += "#";
            t += c;
        }
        t += "#";
        d = manacher_odd(t);
    }

    bool is_palindrome(int l, int r) const {
        int center = l + r + 1;
        int max_len = d[center] - 1;
        int query_len = r - l + 1;
        return max_len >= query_len;
    }

    string get_longest_palindrome(const string& original) const {
        int center = -1, max_len = 0;
        for (int i = 0; i < (int)d.size(); ++i) {
            if (d[i] - 1 > max_len) {
                max_len = d[i] - 1;
                center = i;
            }
        }
        int start_index = (center - max_len) / 2;
        return original.substr(start_index, max_len);
    }
};