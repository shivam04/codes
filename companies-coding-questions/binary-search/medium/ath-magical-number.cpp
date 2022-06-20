int Solution::solve(int A, int B, int C) {
    int mod = 1000000007;
    int L = (B/__gcd(B,C))*C;
    long l = 0;
    long h = (long) A * (long)min(B,C);
    while(l<h) {
        long m = (l+h)/2;
        if(m/B + m/C - m/L < A) {
            l = m+1;
        } else {
            h = m;
        }
        
    }
    return l%mod;
}
