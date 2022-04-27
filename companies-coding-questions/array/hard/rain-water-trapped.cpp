int Solution::trap(const vector<int> &A) {
    int n = A.size();
    int leftMax[n], rightMax[n];
    leftMax[0] = A[0];
    for(int i=1;i<n;i++) {
        leftMax[i] = max(leftMax[i-1], A[i]);
    }
    rightMax[n-1] = A[n-1];
    for(int i=n-2;i>=0;i--) {
        rightMax[i] = max(rightMax[i+1], A[i]);
    }
    int ans = 0;
    for(int i=0;i<n;i++) {
        ans += (min(leftMax[i], rightMax[i]) - A[i]);
    }
    return ans;
}
