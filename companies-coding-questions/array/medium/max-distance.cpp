int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    int leftMin[n];
    int rightMax[n];
    leftMin[0] =A[0];
    rightMax[n-1] = A[n-1];
    for(int i=1;i<n;i++) {
        leftMin[i] = min(leftMin[i-1], A[i]);
    }

    for(int i=n-2;i>=0;i--) {
        rightMax[i] = max(rightMax[i+1], A[i]);
    }
    
    int i = 0, j = 0, maxDiff = INT_MIN;
    while (j < n && i < n) {
        if(leftMin[i]<=rightMax[j]) {
            maxDiff = max(maxDiff, j - i);
            j++;
        } else {
            i++;
        }
    }
    return maxDiff;
}

