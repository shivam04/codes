int Solution::solve(vector<int> &A, vector<int> &B) {
    unordered_map<int, long> xpoints;
    unordered_map<int, long> ypoints;
    int n = A.size();
    for (int i = 0; i < n; i++) {
        xpoints[A[i]]++;
        ypoints[B[i]]++;
    }
    int mod = 1000000007;
    long long ans = 0;
    for(int i=0;i<n;i++) {
        if(xpoints[A[i]]>=1 and ypoints[B[i]]>=1) {
            ans = ans%mod +  ((xpoints[A[i]]%mod - 1 + mod)%mod * (ypoints[B[i]]%mod - 1 + mod))%mod;
        }
    }

    return ans;
}
