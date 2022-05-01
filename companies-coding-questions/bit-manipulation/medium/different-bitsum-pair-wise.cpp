int Solution::cntBits(vector<int> &A) {
    int n = A.size();
    int ans = 0;
    int mod = 1000000007;
    for(int i=0;i<32;i++) {
        int x = (1<<i);
        long cnt = 0;
        for(int j=0;j<n;j++) {
            if(A[j]&x) {
                cnt++;
            }
        }
        ans = (ans%mod +((cnt*((long)n-cnt))*2)%mod)%mod;
    }
    return ans%mod;
}
