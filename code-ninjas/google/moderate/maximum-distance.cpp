int maxDiff(vector<int> &a, int n) {
    int ans = -1000000007;
    vector<int> leftmin(n);
    leftmin[0] = a[0];
    for(int i=1;i<n;i++) {
        leftmin[i] = min(leftmin[i-1], a[i]);
    }
    int i = n-1;
    int j = n-1;
    while(i>=0 and j>=0) {
        if(leftmin[i]<=a[j]) {
            ans = max(ans, j-i);
            i--;
        } else {
            j--;
        }
    }
    return ans;
}

