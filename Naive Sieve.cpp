vector<bool> NaiveSieve(long long n) {
    // Step 1: Initialize a boolean vector with all values set to true (assuming all numbers are prime initially).
    vector<bool> is_prime(n + 5, true);  // n + 5 to avoid out-of-bounds error when accessing n.
    
    // Step 2: Set indices 0 and 1 to false because 0 and 1 are not prime numbers.
    is_prime[0] = is_prime[1] = false;
    
    // Step 3: Start with the first prime number (2) and iterate until the square root of `n`.
    for (long long i = 2; i <= n; i++) {
        if (is_prime[i]) {  // If `i` is prime
            // Step 4: Mark all multiples of `i` as non-prime (false).
            for (long long j = i + i; j <= n; j += i) {
                is_prime[j] = false;  // Marking multiples of `i` as non-prime.
            }
        }
    }
    
    // Step 5: Return the vector containing prime status (true or false) for each number from 0 to `n`.
    return is_prime;
}
