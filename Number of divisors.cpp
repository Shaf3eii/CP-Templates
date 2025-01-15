int number_of_divisors(ll n) {
    int divisors = 0;
    
    // Iterate over all numbers from 1 to sqrt(n)
    for (int i = 1; i < sqrt(n); i++) {
        if (n % i == 0) {
            divisors += 2;  // i and n/i are divisors
        }
    }

    // Check if n is a perfect square, if so, subtract 1 from divisors
    return divisors + (sqrt(n) == (int)sqrt(n));
}
