class Solution {
public:
    double myPowUtil(double x, int m) {
        double ans = 1.0;
        while (m > 0) {
            if (m%2 == 1) {
                ans = ans*x;
            }
            x*=x;
            m/=2;
        }
        return ans;
    }
    double myPow(double x, int n) {
        int m = abs(n);
        double ans = myPowUtil(x,m);

        if (n<0) {
            return (1.0/ans);
        }

        return ans;
    }
};