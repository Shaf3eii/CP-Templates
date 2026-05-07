***
### (a + b) = (a | b) + (a & b)
***
**Bitwise Identities**
- $a \mid b = (a \oplus b) + (a \mathbin{\&} b)$
- $a \oplus (a \mathbin{\&} b) = (a \mid b) \oplus b$
- $b \oplus (a \mathbin{\&} b) = (a \mid b) \oplus a$
- $(a \mathbin{\&} b) \oplus (a \mid b) = a \oplus b$
**Addition Identities**
- $a + b = (a \mid b) + (a \mathbin{\&} b)$
- $a + b = (a \oplus b) + 2(a \mathbin{\&} b)$
**Subtraction Identities**
- $a - b = (a \oplus (a \mathbin{\&} b)) - ((a \mid b) \oplus a)$
- $a - b = ((a \mid b) \oplus b) - ((a \mid b) \oplus a)$
- $a - b = (a \oplus (a \mathbin{\&} b)) - (b \oplus (a \mathbin{\&} b))$
- $a - b = ((a \mid b) \oplus b) - (b \oplus (a \mathbin{\&} b))$
***
- **Position of Most Significant Bit (MSB):** `bit = 31 - __builtin_clz(number)`
- **Position of Least Significant Bit (LSB):** `bit = __builtin_ctz(number)`
- **Next power of $2$ strictly greater than $n$:** `ans = 1 << (32 - __builtin_clz(n - 1))`
***
- **Subarray Bitwise AND:** The set of distinct bitwise AND results of all subarrays of an array (where $a_i \le n$) contains at most $\log_2(n)$ elements. _(This is because every time a running bitwise AND changes, it must turn off at least one bit, and a number $\le n$ has at most $\approx \log_2(n)$ bits)._
***
- **XOR Inequality Property:** For any non-negative integers $x, y, z$ with $x < y < z$:    $$\min(x \oplus y, y \oplus z) < x \oplus z$$
***
