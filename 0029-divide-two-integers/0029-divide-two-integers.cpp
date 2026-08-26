class Solution {
public:
   int divide(int dividend, int divisor) {
    if (divisor == 0)
        return INT_MAX;

    // Overflow case
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    long long a = dividend;
    long long b = divisor;

    // Determine sign of answer
    bool negative = (a < 0) ^ (b < 0);

    // Convert to positive values
    a = abs(a);
    b = abs(b);

    long long quotient = 0;

    while (a >= b) {
        long long temp = b;
        long long multiple = 1;

        // Find largest multiple of divisor using bit shifting
        while ((temp << 1) <= a) {
            temp <<= 1;
            multiple <<= 1;
        }

        a -= temp;
        quotient += multiple;
    }

    if (negative)
        quotient = -quotient;

    return (int)quotient;
}

};