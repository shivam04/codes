vector<int> Solution::solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) {
    int n = A.size();
    int m = A[0].size();
    int mod = 1000000007;

    vector<vector<int>> prefixSum;
    for(int i=0;i<n;i++) {
        vector<int> pp(m,0);
        prefixSum.push_back(pp);
    }
    for(int i=0;i<m;i++) {
        prefixSum[0][i] =  A[0][i]%mod;
    }

    for(int i=1;i<n;i++) {
        for(int j=0;j<m;j++) {
            prefixSum[i][j] = (A[i][j]%mod + prefixSum[i-1][j]%mod)%mod;
            if(prefixSum[i][j]<0) {
                prefixSum[i][j] += mod;
            }
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=1;j<m;j++) {
            prefixSum[i][j] = (prefixSum[i][j]%mod + prefixSum[i][j-1]%mod)%mod;
            if(prefixSum[i][j]<0) {
                prefixSum[i][j] += mod;
            }
        }
    }

    int q = B.size();
    int i = 0;
    vector<int> ans;
    while(i<q) {
        int a = B[i]-1;
        int b = C[i]-1;
        int c = D[i]-1;
        int d = E[i]-1;
        i++;
        int sum = prefixSum[c][d]%mod;
        if(a-1>=0) {
            sum = (sum%mod - prefixSum[a-1][d]%mod)%mod;
            if(sum < 0)
                sum+=mod;
        }
        if(b-1>=0) {
            sum = (sum%mod - prefixSum[c][b-1]%mod)%mod;
            if(sum < 0)
                sum+=mod;
        }
        if(a-1 >= 0 and b-1 >=0){
            sum = (sum%mod + prefixSum[a-1][b-1]%mod)%mod;
            if(sum < 0)
                sum+=mod;
        }
        if(sum < 0) {
            sum+=mod;
        }
        ans.push_back(sum%mod);
    }
    return ans;
}
