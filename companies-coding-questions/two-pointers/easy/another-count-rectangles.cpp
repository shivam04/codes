int Solution::solve(vector<int> &A, int B) {
    int l = 0;
    int mod = 1000000007;
    int r = A.size()-1;
    long cnt = 0;
    long b = (long) B;
    while(l<=r) {
        long al = (long) A[l];
        long ar = (long) A[r];
        if(al*ar < b) {
            cnt += 2*(r-l);
            cnt%=mod;
            cnt++;
            cnt%=mod;
            l++;
        } else {
            r--;
        }
    }
    return cnt%mod;
}