bool isValid(vector<vector<int> > &A, int n, int p) {
    return (A[n][0]<A[p][0] and A[n][1]<A[p][1]);
}
int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(), A.end(), [](vector<int> a, vector<int> b){
        if(a[0]==b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    });
    int n = A.size();
    vector<int> dp(n,1);
    int ans = 0;
    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(isValid(A,j,i)) {
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
