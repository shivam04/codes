int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long l = 1;
    long long r = A;
    long long ans = 0;
    while(l<=r){
        long long mid=(l+r)/2;
        if(mid*mid==A){
            return mid;
        }else if(mid*mid<A){
            ans = mid;
            l=mid+1;
        }else{
            r = mid-1;
        }
    }
    return ans;
}
