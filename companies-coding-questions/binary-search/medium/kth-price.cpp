int Solution::solve(const vector<int> &A, int B) {
    if(B>A.size())
        return -1;
    int l = *min_element(A.begin(), A.end());
    int r = *max_element(A.begin(), A.end());
    int n = A.size();
    while(l<=r) {
        int mid = (l+r)/2;
        int cL = 0, cE = 0;
        for(int i=0;i<n;i++) {
            cL += (A[i]<mid);
            cE += (A[i]==mid);
            if(cL>=B)
                break;
        }
        if(cL < B and cL + cE >= B) {
            return mid;
        } else if(cL>=B) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}
