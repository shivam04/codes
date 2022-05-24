vector<vector<int> > Solution::solve(vector<vector<int> > &A, int B) {
    sort(A.begin(), A.end(), [](vector<int> a, vector<int> b) {
        double p = sqrt(a[0]*a[0] + a[1]*a[1]);
        double q = sqrt(b[0]*b[0] + b[1]*b[1]);
        return p<q;
    });
    vector<vector<int> > ans;
    for(int i=0;i<B;i++) {
        ans.push_back(A[i]);
    }
    return ans;
}
