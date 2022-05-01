int Solution::solve(int A) {
    int ans = 0;
    A++;
    int p = 2;
    int mod = 1000000007;
    ans = A/2;
    ans%=mod;
    while(p<=A) {
        int tp = A/p;
        ans = ans%mod + ((tp/2)*p);
        ans = ans%mod + ((tp&1) ? (A%p) : 0);
        p*=2;
    }
    return ans%mod;
}
