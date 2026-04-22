vector<int> KMP(string& s) {
    int n = (int)s.size();
    vector<int> pi(n);
    for (int i = 1, j; i < n; ++i) {
        j = pi[i - 1];
        while (j and s[j] != s[i]) j = pi[j - 1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

vector<vector<int>> KMP_Automata(string& s) {
    s += '#';
    int n = s.size();
    auto pi = KMP(s);
    vector aut(n, vector<int> (26));
    aut[0][s[0] - 'a'] = 1;
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < 26; ++j)
            if (s[i] - 'a' == j) aut[i][j] = i + 1;
            else                 aut[i][j] = aut[pi[i - 1]][j];
    return aut;
}