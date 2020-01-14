int Solution::findMin(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int l = 0;
    int r = A.size()-1;
    if(r==0)
    return A[r];
    int mid=-1;
    int flag = 0;
    while(l<=r){
        mid = (l+r)/2;
        if(mid<r and A[mid]>A[mid+1])
        {
            flag = 1;
            break;
        }else if(mid>l and A[mid]<A[mid-1]){
            flag = 1;
            mid--;
            break;
        }else if(A[l]>=A[mid]){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    if(!flag){
        return A[0];
    }
    return A[mid+1];
}
