int Solution::sqrt(int A) {
    long long a = (long long)A;
    if(A==0)
        return 0;
    if(A<=3)
        return 1;
    int l = 1;
    int r = A/2;
    int ans;
    while(l<=r) {
        int mid = (l+r)/2;
        long long sqr = (long long)((long long)mid * (long long)mid);
        if(sqr==a) {
            return mid;
        }
        if(sqr<= a) {
            l = mid+1;
            ans = mid;
        } else {
            r = mid-1;
        }
    }
    return ans;
}
