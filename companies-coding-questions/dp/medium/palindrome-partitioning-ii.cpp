int Solution::minCut(string A) {
    int n = A.size();
    vector<vector<int>> p(n,vector<int>(n,0));
    vector<int> c(n,0);
    for(int i=0;i<n;i++) {
        p[i][i] = 1;
    }

    for (int L = 2; L <= n; L++) {
        for (int i = 0; i < n - L + 1; i++) { 
            int j = i + L - 1;
            if (L == 2)
                p[i][j] = (A[i]==A[j]);
            else 
                p[i][j] = (A[i]==A[j]) and p[i+1][j-1];
        }
    }

    for(int i=0;i<n;i++) {
        if(p[0][i] == 1) {
            c[i] = 0;
        } else {
            c[i] = INT_MAX;
            for(int j=0;j<i;j++) {
                if(p[j+1][i] == 1 and 1+c[j] < c[i]) {
                    c[i] = 1 + c[j];
                } 
            }
        }
    }
    return c[n-1];
}
