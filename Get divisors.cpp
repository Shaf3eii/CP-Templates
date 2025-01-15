vector<ll> Get_Divisors(ll n) {
    vector<ll> divisors;
    
    // Iterate over numbers from 1 to sqrt(n)
    for (int i = 1; i < sqrt(n); i++) {
        if (n % i == 0) {
            divisors.push_back(i);       // Add i as a divisor
            divisors.push_back(n / i);   // Add the corresponding pair divisor n/i
        }
    }

    // If n is a perfect square, add sqrt(n) only once
    if (sqrt(n) == int(sqrt(n))) divisors.push_back(sqrt(n));
    
    return divisors;
}
