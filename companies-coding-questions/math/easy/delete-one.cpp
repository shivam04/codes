int Solution::solve(vector<int> &A) {
    int n = A.size();
    if(n==1) {
        return A[0];
    }
    if(n==2) {
        return max(A[0],A[1]);
    }
    int prefix[n];
    prefix[0] = A[0];
    for(int i=1;i<n;i++) {
        prefix[i] = __gcd(prefix[i-1], A[i]);
    }

    int suffix[n+1];
    suffix[n] = 0;
    suffix[n-1] = A[n-1];
    for(int i=n-2;i>=0;i--) {
        suffix[i] = __gcd(suffix[i+1], A[i]);
    }
    int ans = __gcd(prefix[0], suffix[2]);
    for(int i=1;i<n-1;i++) {
        ans = max(ans, __gcd(prefix[i], suffix[i+2]));
    }
    return ans;
}
