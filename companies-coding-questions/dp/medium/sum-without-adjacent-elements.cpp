int Solution::adjacent(vector<vector<int> > &A) {
    int incl = max(A[0][0], A[1][0]);
    int excl = 0;
    int n = A[0].size();
    for(int i=1;i<n;i++) {
        int tt = max(incl, excl);
        incl = excl + max(A[0][i], A[1][i]);
        excl = tt;
    }
    return max(incl, excl);
}
