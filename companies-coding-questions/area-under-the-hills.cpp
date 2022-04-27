string Solution::solve(vector<int> &A) {
    double ans = 0.5*(long)A[0];
    int n = A.size();
    for(int i=1;i<n;i++) {
        ans = ans + (0.5*((long)A[i] + (long)A[i-1]));
    }

    ans = ans + 0.5*(long)A[n-1];
    return to_string((long)ans);
}
