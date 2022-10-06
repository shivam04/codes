unordered_map<int,unordered_map<int,int>> dp;
int ans(vector<int> &A, int i, int j) {
    if(i==j)
        return 0;
    if(dp.find(i)!=dp.end() and dp[i].find(j)!=dp[i].end())
        return dp[i][j];
    int mini = INT_MAX;
    for(int k=i;k<j;k++) {
        mini = min(mini, ans(A, i, k) + ans(A, k+1,j) + A[i-1]*A[k]*A[j]);
    }
    return dp[i][j] = mini;
}
int Solution::solve(vector<int> &A) {
    dp.clear();
    int n = A.size();
    return ans(A, 1, n-1);
}
