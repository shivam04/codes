int Solution::solve(vector<int> &A, int B) {
    int cnt = 0;
    int n = A.size();
    for(int n : A) {
        cnt += (n<=B);
    }
    int bad = 0;
    for(int i=0;i<cnt;i++) {
        bad += (A[i]>B);
    }
    int ans = bad;
    for(int i=0,j=cnt;j<n;j++,i++) {
        if(A[i]>B)
            --bad;
        if(A[j]>B)
            ++bad;
        ans = min(ans, bad);
    }
    return ans;
}
