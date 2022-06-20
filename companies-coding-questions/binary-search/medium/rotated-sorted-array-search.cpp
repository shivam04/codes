int Solution::search(const vector<int> &A, int B) {
    int h = A.size()-1;
    int l = 0;
    while(l<=h) {
        int mid = l + (h-l)/2;
        if(A[mid]==B)
            return mid;
        if(A[l] <= A[mid]) {
            if(B>=A[l] and B<=A[mid]) {
                h = mid-1;
            } else {
                l = mid+1;
            }
        } else if(B>=A[mid] and B<=A[h]) {
            l = mid+1;
        } else {
            h= mid-1;
        }
    }
    return -1;
}
