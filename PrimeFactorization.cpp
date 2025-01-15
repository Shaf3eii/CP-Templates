vector<int> prime_factorization(ll n) {
    vector<int> factors;  // Vector to store the factors
    // Divide by 2 as long as it's divisible
    while (n % 2 == 0) {
        factors.push_back(2);  // 2 is a prime factor
        n /= 2;  // Divide n by 2 to remove factor
    }
    // Iterate through odd numbers from 3 to sqrt(n)
    for (int i = 3; i <= sqrt(n); i += 2) {
        // Divide by i as long as it's divisible
        while (n % i == 0) {
            factors.push_back(i);  // i is a prime factor
            n /= i;  // Divide n by i to remove factor
        }
    }
    // If n is greater than 2, it must be a prime factor
    if (n > 2) {
        factors.push_back(n);  // n is prime
    }
    return factors;  // Return the prime factors
}
