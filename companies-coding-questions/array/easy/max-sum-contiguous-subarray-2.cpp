int Solution::maxSubArray(const vector<int> &A) {
    int cmax = 0;
    int smax = 0;
    int n = A.size();
    int allNeg = 1;
    for(int i=0;i<n;i++) {
        if(A[i]>0) {
            allNeg = 0;
        }
        cmax = max(cmax + A[i], A[i]);
        smax = max(smax, cmax);
    }
    if(allNeg) {
        return *max_element(A.begin(), A.end());
    }
    return smax;
}
