class Solution{
    public:
    int dp[1000001];
    bool solve(vector<int> &arr, int s, int n, int k, int m) {
        if(s>=n) return true;
        if(dp[s] != -1) return dp[s];
        for(int i=s+k-1;i<n;i++) {
            int d = arr[i]-arr[s];
            if(d>m) break;
            bool ans = solve(arr,i+1,n,k,m);
            if(ans) return dp[s] = true;
        }
        return dp[s] = false;
    }
    bool partitionArray(int N, int K, int M, vector<int> &A){
        sort(A.begin(), A.end());
        memset(dp,-1,sizeof dp);
        return solve(A, 0, N, K, M);
    }
};