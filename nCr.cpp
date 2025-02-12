const int N = 1e6 + 5, Mod = 1e9 + 7;  // Define the maximum limit for precomputed values

int f[N], inv[N], finv[N];  // Arrays to store factorials, modular inverses, and inverse factorials

// Function to precompute factorials, modular inverses, and inverse factorials
void prec() {
    f[0] = 1;  // Base case: 0! = 1
    for (int i = 1; i < N; i++) 
        f[i] = 1LL * i * f[i - 1] % Mod;  // Compute factorials modulo Mod

    inv[1] = 1;  // Base case: The modular inverse of 1 is 1
    for (int i = 2; i < N; i++) {
        // Compute modular inverse using the property: inv[i] = (-(Mod / i) * inv[Mod % i]) % Mod
        inv[i] = (-(1LL * Mod / i) * inv[Mod % i]) % Mod;
        inv[i] = (inv[i] + Mod) % Mod;  // Ensure positive value
    }

    finv[0] = 1;  // Base case: 0! inverse = 1
    for (int i = 1; i < N; i++) 
        finv[i] = 1LL * inv[i] * finv[i - 1] % Mod;  // Compute inverse factorials modulo Mod
}

// Function to compute nCr (binomial coefficient) efficiently
int ncr(int n, int r) {
    if (n < r || n < 0 || r < 0) return 0;  // Edge case: nCr is 0 if r > n or negative values
    return 1LL * f[n] * finv[n - r] % Mod * finv[r] % Mod;  // Compute nCr using precomputed values
}
