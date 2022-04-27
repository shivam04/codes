int Solution::solve(vector<int> &A) {
    int n = A.size();
    long long prefix[n+1];
    prefix[0] = long(A[0]);
    for(int i=1;i<n;i++) {
        prefix[i] = prefix[i-1] + A[i];
    }
    for(int i=0;i<n-1;i++) {
        int p = prefix[i];
        int q = prefix[n-1] - prefix[i+1];
        if(p==q) {
            return i+1;
        }
    }
    if(prefix[n-1]-prefix[0] == 0) {
        return 0;
    }
    return -1;
}
