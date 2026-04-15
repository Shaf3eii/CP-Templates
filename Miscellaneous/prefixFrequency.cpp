constexpr int N = 1e5+5;
vector<vector<int>> prefix_freq(N, vector<int>(26, 0));
void pre(string s) {
    prefix_freq[0][s[0] - 'a'] = 1;
 
    for (int i = 1; i < sz(s); ++i) {
        for (int ch = 0; ch < 26; ++ch)
            prefix_freq[i][ch] = prefix_freq[i - 1][ch];
 
        prefix_freq[i][s[i] - 'a']++;
    }
}
 
