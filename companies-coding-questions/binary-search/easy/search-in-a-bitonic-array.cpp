//O(2logn)
int Solution::solve(vector<int> &A, int B) {
    int l  = 0;
    int n = A.size();
    int h = n-1;
    int peak = -1;
    while(l<=h) {
        int mid = l + (h-l)/2;
        if((mid==0 or A[mid-1] <= A[mid]) and (mid==n-1 || A[mid]>=A[mid+1])) {
           peak = mid;
           break;
        } else if(mid > 0 and A[mid-1] > A[mid]) {
            h = mid-1;
        } else {
            l = mid+1;
        }
    }
    
    l = 0;
    h = peak;
    while(l<=h) {
        int mid = (l+h)/2;
        if(A[mid]==B) 
            return mid;
        else if(A[mid]<B)
            l=mid+1;
        else 
            h = mid-1;
    }

    l = peak+1;
    h = n-1;
    while(l<=h) {
        int mid = (l+h)/2;
        if(A[mid]==B) 
            return mid;
        else if(A[mid]>B)
            l=mid+1;
        else 
            h = mid-1;
    }
    return -1;
}


//O(logn)
