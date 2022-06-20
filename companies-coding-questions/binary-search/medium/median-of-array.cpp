//O(N) memory and O(n+m) time
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> AB;
    int i = 0, j = 0;
    int n = A.size();
    int m = B.size();
    while(i<n and j<m) {
        if(A[i]<B[j]) {
            AB.push_back(A[i++]);
        } else {
            AB.push_back(B[j++]);
        }
    }
    while(i<n) {
        AB.push_back(A[i++]);
    }

    while(j<m) {
        AB.push_back(B[j++]);
    }
    int k = AB.size();
    if(k%2) {
        return AB[k/2];
    } 
    int p =k/2;
    return (AB[p]+AB[p-1])/2.0;
}


//O(logN)

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int m = B.size();
    if(n > m)
        return findMedianSortedArrays(B,A);
    int l = 0;
    int h = n;
    int rMid = (n+m+1)/2;
    while(l<=h) {
        int mid = (l+h)/2;
        int lAS = mid;
        int lBS = rMid - mid;
        int lA = lAS > 0 ? A[lAS-1] : INT_MIN;
        int lB = lBS > 0 ? B[lBS-1] : INT_MIN;
        int rA = lAS < n ? A[lAS] : INT_MAX;
        int rB = lBS < m ? B[lBS] : INT_MAX;
        if(lA <= rB and lB <= rA) {
            if((m+n)%2==0) {
                return (max(lA, lB) + min(rA,rB))/2.0;
            } else {
                return max(lA,lB);
            }
        } else if(lA > rB) {
            h = mid-1;
        } else {
            l = mid+1;
        }
    }
    return 0.0;
}
