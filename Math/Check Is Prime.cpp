bool is_prime(ll n) {
    // Check if n is less than 2 or an even number other than 2
    if (n < 2 || (n % 2 == 0 && n != 2)) return false;
    
    // 2 is prime, return true if n is 2
    if (n == 2) return true;
    
    // Check for divisibility by odd numbers starting from 3 up to sqrt(n)
    for (int i = 3; i * i <= (n); i += 2) {
        if (n % i == 0) return false;  // If n is divisible by i, it's not prime
    }
    
    // If no divisors are found, n is prime
    return true;
}
