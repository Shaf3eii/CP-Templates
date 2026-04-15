long long fastPower(long long base, long long power, long long mod) {
    long long res = 1;
    while (power) {
        if (power & 1) {
            res = ((res % mod) * (base % mod)) % mod;
            power -= 1;
        } else {
            base = ((base % mod) * (base % mod)) % mod;
            power >>= 1;
        }
    }
    return res;
}
