vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    int p = n+(n-1);
    int i;
    vector<vector<int> > v;
    v.resize(p);
    for(i=0;i<p;i++){
        if(i<=n-1){
            int k = 0;
            for(int j=i;j>=0;j--){
                v[i].push_back(A[k++][j]);
            }
        }else{
            int k = i-n+1;
            for(int j=n-1;j>i-n;j--){
                v[i].push_back(A[k++][j]);
            }
        }
    }
    return v;
}
