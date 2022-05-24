const long long int MOD = 1000000007;
int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    int minSum = 0, maxSum = 0;
    for (int i = 0; i < n; i++) {
        maxSum = 2*maxSum + A[n-i-1];
        maxSum %= MOD;
        minSum = 2*minSum + A[i];
        minSum %= MOD;
    }
    return (maxSum - minSum + MOD)%MOD;
}
