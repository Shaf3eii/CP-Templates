#include<bits/stdc++.h>
using namespace std;

// Checks if kth bit of x is set (1) or not (0)
int check_kth_bit(int x, int k) {
  return (x >> k) & 1;
}

// Sets the kth bit of x to 1 and returns the result
int set_kth_bit(int x, int k) {
    return x | (1 << k);
}

// Sets the kth bit of x to 0 and returns the result
int unset_kth_bit(int x, int k) {
    return x & (~(1 << k));
}

// Toggles the kth bit of x and returns the result
int toggle_kth_bit(int x, int k) {
    return x ^ (1 << k);
}

// Checks if x is a power of 2
bool isPowerOfTwo(unsigned int n) {
    return n && !(n & (n - 1));
}
bool isPowerOfTwo(int n) {
    return n != 1 and __builtin_popcount(n) == 1;
}

// Clear all trailing ones and return the result
int Clear_all_trailing_ones(int n){
    return n&(n+1);
}

// Clear last set bit and return the result
int Clear_last_set_bit(int n){
    return n&(n-1);
}

// Count the no. 1s
int count_set_bits(int n){
    return __builtin_popcount(n);
}

// Check if n is divisible by power of 2 (k is the power of 2 -> k = 3 (2 ^ 3 -> 8))
bool isDivisibleByPowerOf2(int n, int k) {
    int powerOf2 = 1 << k;
    return (n & (powerOf2 - 1)) == 0;
}

// Get the last set bit
int Extract_last_bit(int n){
    return n&-n;
}

// Set the right most cleared bit
int Set_right_most_cleared_bit(int n){
    return n|(n+1);
}

int main() {
  // Bitwise AND (&)
  int and_result = 12 & 25;  // 12 (binary 1100) & 25 (binary 11001) = 8 (binary 1000)
  cout << "AND result: " << and_result << '\n'; // Output: 8

  // Bitwise OR (|)
  int or_result = 12 | 25;  // 12 (binary 1100) | 25 (binary 11001) = 29 (binary 11101)
  cout << "OR result: " << or_result << '\n'; // Output: 29

  // Bitwise XOR (^)
  int xor_result = 12 ^ 25;  // 12 (binary 1100) ^ 25 (binary 11001) = 21 (binary 10101)
  cout << "XOR result: " << xor_result << '\n'; // Output: 21

  // Bitwise NOT (~)
  int not_result = ~12;
  cout << "NOT result: " << not_result << '\n'; // Output: -13

  // Left shift (<<)
  int left_shift_result = 3 << 2;  // 3 (binary 11) << 2 = 12 (binary 1100)
  cout << "Left shift result: " << left_shift_result << '\n'; // Output: 12

  // Right shift (>>)
  int right_shift_result = 12 >> 2;  // 12 (binary 1100) >> 2 = 3 (binary 11)
  cout << "Right shift result: " << right_shift_result << '\n'; // Output: 3

  // Difference between 1 << x and 1LL << x
  int x = 31;
  long long res1 = 1 << x;  // This can lead to overflow if x is large
  long long res2 = 1LL << x;  // This avoids overflow since we're shifting on a long long
  cout << "1 << x result: " << res1 << '\n';  // Output: -2147483648 (due to overflow)
  cout << "1LL << x result: " << res2 << "\n\n";  // Output: 2147483648 (correct value)


  x = 11; // binary representation: 1011

  cout << "Check 2nd bit of 11: " << check_kth_bit(x, 2) << '\n'; // Output: 0
  cout << "Set bits in 11 are at positions: ";
  cout << "Number of set bits in 11: " << count_set_bits(x) << '\n'; // Output: 3
  cout << "11 after setting 2nd bit: " << set_kth_bit(x, 2) << '\n'; // Output: 15
  cout << "15 after unsetting 2nd bit: " << unset_kth_bit(15, 2) << '\n'; // Output: 11
  cout << "11 after toggling 3rd bit: " << toggle_kth_bit(x, 3) << '\n'; // Output: 3
  cout << "Is 8 a power of 2: " << isPowerOfTwo(8) << '\n'; // Output: 1 (true)

  return 0;
}
