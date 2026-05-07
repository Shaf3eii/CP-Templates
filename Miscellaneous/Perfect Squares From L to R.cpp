// Stores all distinct perfect powers (a^b) where a >= 2 and b >= 2
vector<long long> perfectPowers;

// Precompute all perfect powers up to maxR (e.g. 1e18)
// Complexity: O(N log N)
//   - b goes up to ~60 because 2^60 > 1e18
//   - a is bounded by maxR^(1/b)
//   - total generated numbers is small
void precompute(long long maxR) {

    // Iterate over exponent b (b >= 2)
    for (int b = 2; b <= 60; b++) {

        // Iterate over base a (a >= 2)
        for (long long a = 2;; a++) {

            // Compute a^b safely using 128-bit to avoid overflow
            __int128 val = 1;
            for (int i = 0; i < b; i++) val *= a;

            // Stop when exceeding the maximum limit
            if (val > maxR) break;

            perfectPowers.push_back((long long)val);
        }
    }

    // Sort to allow binary search
    sort(begin(perfectPowers), end(perfectPowers));

    // Remove duplicates (e.g. 64 = 2^6 = 4^3 = 8^2)
    perfectPowers.erase(
        unique(begin(perfectPowers), end(perfectPowers)),
        end(perfectPowers)
    );
}

// Count how many perfect powers lie in the range [L, R]
// Uses binary search
// Complexity: O(log N)
long long countPerfectPowers(long long L, long long R) {
    return upper_bound(perfectPowers.begin(), perfectPowers.end(), R)
         - lower_bound(perfectPowers.begin(), perfectPowers.end(), L);
}