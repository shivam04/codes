class Solution {
public:
    int divide(int dividend, int divisor) {
        long a = (long)dividend;
        long b = (long)divisor;
        long c = a/b;
        if (c > INT_MAX) {
            return INT_MAX;
        } else if (c < INT_MIN) {
            return INT_MIN;
        }
        return c;
    }
};