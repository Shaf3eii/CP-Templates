/**
* Online KMP Implementation
 * This class implements the memory-optimized KMP. Even if the text stream
 * is millions of characters long, this only uses O(M) memory, where M is the length of the pattern.
 */
class OnlineKMP {
private:
    string pattern;
    vector<int> pi; // Prefix function values for the pattern
    int state;           // The current "state" (length of the matched prefix)
public:
    OnlineKMP(const string& p) : pattern(p), state(0) {
        int m = pattern.length();
        pi.assign(m, 0);
        // 1. Precompute the prefix function for the pattern.
        // This is the "M+1" storage referred to: we keep the pattern
        // and its pi values to guide the jumps for any future text.
        for (int i = 1; i < m; i++) {
            int j = pi[i - 1];
            while (j and pattern[i] != pattern[j])
                j = pi[j - 1];
            if (pattern[i] == pattern[j])
                j++;
            pi[i] = j;
        }
    }
    /*
        Processes a single character from the stream as it arrives.
        Time complexity: O(1) amortized.
    */
    bool process(char c) {
        int m = pattern.length();
        // 2. The "Online" logic:
        // Use the stored pattern characters and pi values to update the state.
        while (state and c != pattern[state]) state = pi[state - 1];

        if (c == pattern[state]) state++;
        // 3. Match detection:
        if (state == m) {
            // A match is found. We reset the state using the prefix function
            // to allow for overlapping matches (e.g., "aba" in "ababa").
            state = pi[m - 1];
            return true;
        }
        return false;
    }
};
