namespace combinatorics
{
    int MOD;
    vector<int> fac, inv, finv;
    int nCr(int x, int y) {
        if(x < 0 || y > x || y < 0) return(0);
        return(fac[x] * finv[y] % MOD * finv[x-y] % MOD);
    }
    int nPr(int x, int y) {
        if(x < 0 || y > x || y < 0) return(0);
        return fac[x] * finv[x-y] % MOD;
    }
    int power(int b, int n) {
        b %= MOD;
        int s = 1;
        while(n > 0) {
            if (n & 1) s = s * b % MOD;
            b = b * b % MOD;
            n /= 2;
        }
        return s;
    }
    void init(int n,int mod) {
        fac.resize(n + 1);
        inv.resize(n + 1);
        finv.resize(n + 1);
        MOD = mod;
        fac[0] = inv[0] = inv[1] = finv[0] = finv[1] = 1;
        for(int i = 1;i <= n; ++i) fac[i] = fac[i - 1] * i % MOD;
        for(int i = 2; i <= n; ++i) inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
        for(int i = 2; i <= n; ++i) finv[i] = finv[i - 1] * inv[i] % MOD;
    }
    int mul(int a, int b) {return ((a % MOD) * (b % MOD)) % MOD;}
    int add(int a, int b) {return ((a % MOD) + (b % MOD)) % MOD;}
    int sub(int a, int b) {return (((a - b) % MOD) + MOD) % MOD;}
    int divide(int a, int b) {return mul(a,power(b,MOD - 2));}
    int Inv(int x) {return power(x,MOD - 2);}
    int catalan(int n) {return (nCr(2 * n,n) * Inv(n + 1)) % MOD;}
    int StarsAndPars(int n, int k) {return nCr(n + k - 1,k - 1);}
};
using namespace combinatorics;
