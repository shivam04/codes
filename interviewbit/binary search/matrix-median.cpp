int Solution::findMedian(vector<vector<int> > &A) {
        int mn = A[0][0], mx = A[0][0], n = A.size(), m = A[0].size();
    for (int i = 0; i < n; ++i) {
        if (A[i][0] < mn) mn = A[i][0];
        if (A[i][m-1] > mx) mx = A[i][m-1];
    }
    
    int desired = (n * m + 1) / 2;
    while (mn < mx) {
        int mid = mn + (mx - mn) / 2;
        int place = 0;
        for (int i = 0; i < n; ++i)
            place += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        if (place < desired)
            mn = mid + 1;
        else
            mx = mid;
    }
    return mn;
}
