int Solution::solve(vector<int> &A, int B) {
    if(A.size()<B || B==0)
        return 0;
    sort(A.begin(), A.end());
    int ans = INT_MAX;
    int n = A.size();
    for(int i=n-1;i>=B;i--) {
        ans = min(ans, A[i]-A[i-B+1]);
    }
    return ans;
}
