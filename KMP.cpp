#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(string &pattern) {
    int sz = (int)pattern.size();
    vector<int> lps(sz, 0); // Initialize LPS array with 0
    int len = 0; // Length of the previous longest prefix suffix

    // Start from the second character and calculate LPS for each position
    for (int i = 1; i < sz; ++i) {
        if (pattern[i] == pattern[len]) {
            // Characters match; increment length and update LPS
            lps[i] = ++len;
        } else {
            // Characters don't match
            if (len != 0) {
                // Use the LPS value of the previous position to skip mismatched characters
                len = lps[len - 1];
                --i; // Retry the current character with the updated length
            } else {
                // No prefix suffix match; set LPS[i] to 0
                lps[i] = 0;
            }
        }
    }
    return lps;
}

bool KMP(string &s, string &pat) {
    vector<int> lps = buildLPS(pat); // Build LPS array for the pattern
    int i = 0, j = 0; // Pointers for the string `s` and the pattern `pat`
    while (i < (int)s.size()) {
        if (s[i] == pat[j]) {
            // Characters match; move both pointers
            i++;
            j++;
            if (j == (int)pat.size()) return true; // Full match found
        } else {
            // Characters don't match
            if (j != 0) {
                // Use LPS to skip mismatched characters
                j = lps[j - 1];
            } else {
                // Move `i` if `j` is at the beginning
                i++;
            }
        }
    }
    return false; // No match found
}



int main() {
    string s, p;
    cin >> s >> p;
    cout << (KMP(s, p) ? "YES\n" : "NO\n");
    return 0;
}
