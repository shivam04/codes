vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> p(A,0);
    for(int i=0;i<B.size();i++) {
        int s = B[i][0]-2;
        int e = B[i][1] - 1;
        if(s>=0)
            p[s] -= B[i][2];
        p[e] += B[i][2];
    }

    for(int i=A-2;i>=0;i--) {
        p[i] += p[i+1];
    }
    return p;
}