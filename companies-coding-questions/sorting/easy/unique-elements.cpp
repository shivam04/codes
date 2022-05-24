int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    int p = A[0];
    int cnt = 0;
    for(int i=1;i<n;i++) {
        if(A[i]<=p) {
            p+=1;
            cnt+=(p-A[i]);
            A[i]=p;
        } else {
            p = A[i];
        }
    }
    return cnt;
}
