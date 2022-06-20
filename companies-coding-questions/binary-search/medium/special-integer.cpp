int getSum(vector<int> A, int mid, int B) {
    int k = 0;
    long ans = 0;
    int c = 1;
    for(int i=0;i<mid;i++) {
        ans += (long)A[i];
    }
    if(ans>B)
        return false;
    for(int i=mid;i<A.size();i++) {
        ans += (long)A[i];
        ans -= (long)A[i-mid];
        if(ans>B)
            return false;
    }
    return true;
}
int Solution::solve(vector<int> &A, int B) {
    int l = 1;
    int r = A.size();
    int ans = 0;
    while(l<=r) {
        int mid = (l+r)/2;
        if(getSum(A, mid,B)) {
            ans = max(ans, mid);
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    return ans;
}
