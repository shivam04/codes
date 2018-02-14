vector<vector<int> > Solution::generate(int A) {
    vector<vector<int> > v;
    if(A==0)
    return v;
    v.resize(A);
    v[0].push_back(1);
    if(A==1)
    return v;
    v[1].push_back(1);
    v[1].push_back(1);
    if(A==2)
    return v;
    int i,j;
    for(i=3;i<=A;i++){
        v[i-1].resize(i);
        v[i-1][0] = 1;
        v[i-1][i-1] = 1;
        for(j=1;j<i-1;j++){
            v[i-1][j] = v[i-2][j]+v[i-2][j-1];
        }
    }
    return v;
}
