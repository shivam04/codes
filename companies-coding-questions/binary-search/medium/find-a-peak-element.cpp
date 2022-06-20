int Solution::solve(vector<int> &A) {
    int l  = 0;
    int n = A.size();
    int h = n-1;
    int peak = -1;
    while(l<=h) {
        int mid = l + (h-l)/2;
        if((mid==0 or A[mid-1] <= A[mid]) and (mid==n-1 || A[mid]>=A[mid+1])) {
           return A[mid];
        } else if(mid > 0 and A[mid-1] > A[mid]) {
           h = mid-1;
        } else {
           l = mid+1;
        }
    }
    return peak;
}
