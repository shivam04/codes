int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int l = 0;
    int r = A.size()-1;
    int cnt = 0;
    while(l<r) {
        if(A[l]+A[r]==B) {
            cnt++;
            l++;
            r--;
        } else if(A[l] + A[r]<B) {
            l++;
        } else {
            r--;
        }
    }
    return cnt;
}
