int Solution::searchInsert(vector<int> &A, int B) {
    int n = A.size();
    int l = 0;
    int h = n-1;
    int ans = -1;
    while(l<=h) {
        int mid = l + (h-l)/2;
        if(A[mid]<B) {
            l = mid+1;
        } else {
            h = mid-1;
        }
    }
    while(l < n and A[l] < B) {
        l++;
    }
    return l;
}
