vector<long long> primeFactors(long long x) {
    vector<long long> factors;
    for (int i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            factors.push_back(i);
            x /= i;
        }
    }

    if (x > 1) {
        factors.push_back(x);
    }

    return factors;
}
