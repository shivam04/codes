string Solution::solve(vector<int> &A) {
    int n = A.size();
    if(n<=2)
    return "YES";
    int mx = max(A[n-1], A[n-2]);
    int mi = min(A[n-1], A[n-2]);
    for(int i = n - 3; i >= 0; i--) {
        if(A[i] < mi) 
            mi = A[i];
        else if (A[i] > mx)
            mx = A[i];
        else
            return "NO";
    }
    return "YES";
}
