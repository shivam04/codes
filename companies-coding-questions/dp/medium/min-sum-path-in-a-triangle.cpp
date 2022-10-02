int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n,1000000));

    dp[0][0] = A[0][0];
    for(int i=1;i<n;i++) {
        int m = A[i].size();
        for(int j=0;j<m;j++) {
            if(j==0) {
                dp[i][j] = dp[i-1][j] + A[i][j];
            } else {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + A[i][j];
            }
        }
    }
    return *min_element(dp[n-1].begin(), dp[n-1].end());
}
