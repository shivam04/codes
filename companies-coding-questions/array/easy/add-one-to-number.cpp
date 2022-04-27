vector<int> Solution::plusOne(vector<int> &A) {
    int n = A.size();
    int p = A[n-1] + 1;
    int c = p/10;
    A[n-1] = p%10;
    for(int i=n-2;i>=0;i--) {
        p = A[i] + c;
        A[i] = p%10;
        c=p/10;
    }
    if(c==1) {
        A.insert(A.begin(),1);
    }
    int fi = 0;
    for(int i=0;i<n;i++) {
        if(A[i]>0) {
            fi=i;
            break;
        }
    }
    vector<int> ans (A.begin()+fi, A.end());
    return ans;
}
