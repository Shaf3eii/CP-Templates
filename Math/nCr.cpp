const int N = 1e6 + 5, Mod = 1e9 + 7; 

int f[N], inv[N], finv[N]; 

void prec() {
    f[0] = 1;  
    for (int i = 1; i < N; i++) 
        f[i] = 1LL * i * f[i - 1] % Mod; 

    inv[1] = 1;  
    for (int i = 2; i < N; i++) {
        inv[i] = (-(1LL * Mod / i) * inv[Mod % i]) % Mod;
        inv[i] = (inv[i] + Mod) % Mod;  
    }

    finv[0] = 1;  
    for (int i = 1; i < N; i++) 
        finv[i] = 1LL * inv[i] * finv[i - 1] % Mod;
}

int ncr(int n, int r) {
    if (n < r || n < 0 || r < 0) return 0;
    return 1LL * f[n] * finv[n - r] % Mod * finv[r] % Mod; 
}
