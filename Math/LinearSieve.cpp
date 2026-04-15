vector<int> LinearSieve(int n) {
    vector<bool> is_prime(n + 2, true);  // Initialize a boolean array for prime checks
    vector<int> primes;  // Vector to store the prime numbers
    is_prime[0] = is_prime[1] = false;  // 0 and 1 are not prime
    for (int i = 2; i <= n; ++i) {  // Loop through all numbers from 2 to n
        if (is_prime[i]) {  // If the current number is prime
            primes.push_back(i);  // Add it to the primes list
        }
        // Mark multiples of primes as non-prime
        for (auto p : primes) {
            if (i * p > n) break;  // Stop if the product exceeds n
            is_prime[i * p] = false;  // Mark the product as non-prime
            if (i % p == 0) break;  // If i is divisible by p, break to avoid marking higher multiples
        }
    }
    return primes;  // Return the list of primes
}
