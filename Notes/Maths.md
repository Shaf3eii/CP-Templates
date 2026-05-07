***
## Counting Rectangles Inside a Grid
- The number of rectangles of size $x*y$ inside a $k*k$ grid is:
$$\text{count}(x, y) = \begin{cases} (k - x + 1)(k - y + 1), & \text{if } x \le k \text{ and } y \le k \\ 0, & \text{otherwise} \end{cases}$$
***
- ### Manhattan Distance – Useful Formula

For two points
$$A = (X_i, Y_i), \quad B = (x, y)$$
The Manhattan distance is defined as:
$$|X_i - x| + |Y_i - y|$$
This can be rewritten as:
$$|X_i - x| + |Y_i - y| = \max \begin{cases} (X_i + Y_i) - (x + y) \\ (X_i - Y_i) - (x - y) \\ (-X_i + Y_i) - (-x + y) \\ (-X_i - Y_i) - (-x - y) \end{cases}$$
### Farthest Manhattan Distance in a Range
Given a set of points $(X_i, Y_i)$ for $i \in [L, R]$, the farthest distance from point $(x, y)$ is:
$$\max_{i \in [L, R]} (|X_i - x| + |Y_i - y|) = \max \begin{cases} \max(X_i + Y_i) - (x + y) \\ \max(X_i - Y_i) - (x - y) \\ \max(-X_i + Y_i) - (-x + y) \\ \max(-X_i - Y_i) - (-x - y) \end{cases}$$
where each `max` is taken over $i \in [L, R]$.
***
- To get the summation of numbers in a range (difference is arithmetic sequence)
$$
n * ((a1 + an) / 2)
$$
***
For any $n$:
- Number of groups of size $\ge 2$:
$$\sum_{k=2}^{n} \binom{n}{k}$$
Or faster:
$$2^n - n - 1$$
(we subtract subsets of size 0 and 1)
***
### Modulo Properties
- $a \mathbin{\%} 3 \rightarrow -2, -1, 0, 1, 2 \quad [\text{for } a \text{ negative or positive}]$
- $\text{If } a \mathbin{\%} n = b \mathbin{\%} n \implies (a - b) \mathbin{\%} n = 0$
- $(a \mathbin{\%} n) \mathbin{\%} n = a \mathbin{\%} n$
- $(n^x) \mathbin{\%} n = 0 \quad \text{for any } x \ge 0$
- $-a \mathbin{\%} n \neq a \mathbin{\%} n$
- $((-a \mathbin{\%} n) + (a \mathbin{\%} n)) \mathbin{\%} n = 0$
***
### GCD Properties
- $\gcd(a, b) = \gcd(a - b, b) = \gcd(a + b, b)$
- $\text{If } \gcd(a, b) = d \implies \gcd(a/d, b/d) = 1$
- $\gcd(a, b, c) = \gcd(\gcd(a, b), c)$
***
### Large Number Divisibility (String Modulo)
To check if a large number represented as a string $s$ (of length $n$) is divisible by an integer $m$, you can compute the remainder iteratively from left to right.
**1. Initialize the remainder:**
$$\text{rem} = 0$$
**2. Iterate through each character $s[i]$ from $i = 0$ to $n - 1$:**
$$\text{rem} = (\text{rem} \times 10 + (s[i] - \text{'0'})) \mathbin{\%} m$$
**3. Final Check:**
$$\text{If } \text{rem} = 0 \implies s \text{ is divisible by } m$$
***
> $$\gcd(X, Y) \times \operatorname{lcm}(X, Y) = X \times Y \implies \frac{\operatorname{lcm}(X, Y)}{X \cdot Y} = \frac{1}{\gcd(X, Y)}$$
> So, we can conclude that for any pair $(X, Y)$ if their gcd is $1$ then the pair contributes $1$ to the final answer. Otherwise, it contributes $0$.
***
### Distance Between Two Points (Euclidean Distance)
The distance $d$ between two points $(x_1, y_1)$ and $(x_2, y_2)$ is defined by the mathematical formula:
$$d = \sqrt{(x_1 - x_2)^2 + (y_1 - y_2)^2}$$
```c++
double getDistance(int x1, int y1, int x2, int y2) {
    int x = x1 - x2;
    int y = y1 - y2;
    return sqrt(1.0 * x * x + 1.0 * y * y); // 1.0 to ensure floating point computation
}
```
***
### Logarithm Change of Base
To calculate the logarithm of a number $x$ to an arbitrary base $b$, you can use the **change of base formula**, which allows you to use standard natural logarithms ($\ln$) or base-10 logarithms ($\log_{10}$):
$$\log_{b}(x) = \frac{\log_c(x)}{\log_c(b)}$$
$$\log_{\text{base}}(x) = \frac{\ln(x)}{\ln(\text{base})}$$
```c++
double logBase(double x, double base) {
    return log(x) / log(base);
}
```
***
### Euclidean Division (Division Algorithm)
For any two integers $a$ and $b$ (where $b \neq 0$), there exist unique integers $q$ (the quotient) and $r$ (the remainder) such that:
$$a = bq + r$$
$$\text{where} \quad 0 \le r < b$$
_(Note: If $b$ can be a negative integer, the condition for the remainder is usually generalized as $0 \le r < |b|$)_
***
**Prime Number Bound:** The number of primes smaller than $n$ is commonly bounded by $\frac{n}{\log_2(n)}$. _(Note: The formal Prime Number Theorem states the asymptotic count is $\pi(n) \approx \frac{n}{\ln(n)}$)._
***
**Prefix GCDs:** The set of distinct GCDs of all prefixes of an array (where $a_i \le n$) contains at most $\log_2(n)$ elements. _(This is because every time a running GCD changes, it must decrease by at least a factor of 2)._
***
**Logarithm Recurrence:** $\log_2(n) = \log_2(n / 2) + 1$
***
**Modulo Difference:** If $x \mathbin{\%} m = y \mathbin{\%} m$, then $(|x - y|) \mathbin{\%} m = 0$
***
**Logarithm Product Rule:** $\log(ab) = \log(a) + \log(b)$
***
- **8-Direction Movement (Chebyshev Distance):** If movement is allowed in 8 directions (up, down, left, right, and the 4 diagonals), the minimum number of steps required to move from $(x_1, y_1)$ to $(x_2, y_2)$ is:
$$\text{distance} = \max(|x_2 - x_1|, |y_2 - y_1|)$$
- **4-Direction Movement (Manhattan Distance):** If movement is allowed in 4 directions only (up, down, left, right—no diagonals), the minimum number of steps between $(x_1, y_1)$ and $(x_2, y_2)$ is:
$$\text{distance} = |x_2 - x_1| + |y_2 - y_1|$$
***
