int Solution::findMinXor(vector<int> &A) {
    int mine = INT_MAX;
    int n = A.size();
    sort(A.begin(), A.end());
    for(int i=0;i<n-1;i++) {
        mine = min(mine, A[i]^A[i+1]);
    }
    return mine;
}
