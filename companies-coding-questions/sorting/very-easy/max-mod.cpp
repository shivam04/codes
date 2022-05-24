int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    int fm = A[A.size()-1], sm =INT_MIN;
    for(int i=A.size()-2;i>=0;i--) {
        if(A[i]!=fm) {
            sm = max(sm, A[i]);
        }
    }
    if(sm==INT_MIN)
        return 0;
    return sm;
}
