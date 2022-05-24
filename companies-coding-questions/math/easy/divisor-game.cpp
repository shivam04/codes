int Solution::solve(int A, int B, int C) {
    long a = A;
    long b = B;
    long c = C;
    long p = (b*c)/__gcd(b,c);
    long l = p;
    int cnt = 0;
    while(l<=a) {
        cnt++;
        l+=p;
    }
    return cnt;
}
