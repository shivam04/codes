vector<vector<int> > Solution::prettyPrint(int A) {
    vector<vector<int> > v;
    int n=A+A-1;
    v.resize(n);
    for(int i=0;i<=n/2;i++){
        v[i].resize(n);
        if(i==n/2){
            for(int j=0;j<=n/2;j++){
                v[i][j]=A-j;    
            }
            for(int j=n/2+1;j<n;j++){
                v[i][j]=v[i][n-j-1];
            }
        }else{
            int s = i;
            int e = n-i-1;
            for(int j=s;j<=e;j++){
                v[i][j]=A-i;
            }
            for(int j=0;j<s;j++){
                v[i][j]=A-j;
            }
            for(int j=n-1;j>e;j--){
                v[i][j]=v[i][n-j-1];
            }
        }
    }
    for(int i=n/2+1;i<n;i++){
        v[i]=v[n-i-1];
    }
    return v;
}
