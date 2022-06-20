bool isPossible(vector<int> arr, int m, int k) {
    int lastUsed = arr[0];
    int cnt = 1;
    int n = arr.size();
    for(int i=1;i<n;i++) {
        if(arr[i] - lastUsed >= m) {
            cnt++;
            lastUsed = arr[i];
        }
    }
    return cnt>=k;
}
int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int l = 1;
    int n = A.size();
    int r = A[n-1] - A[0];
    int ans = 1;
    while(l<=r) {
        int m = (l+r)/2;
        if(isPossible(A, m, B)) {
            ans = max(ans, m);
            l = m+1;
        } else {
            r = m-1;
        }
    }
    return ans;
}
