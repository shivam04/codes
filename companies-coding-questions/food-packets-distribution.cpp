bool check(vector<int> A, int m, int B) {
    int req = 0;
    for(int i=0;i<A.size();i++) {
        req += (A[i]/m);
    }
    return req>=B;
}
int Solution::solve(vector<int> &A, int B) {
    long sum = 0;
    int ans = -1;
    for(int s: A)
        sum+=s;
    int l = 1;
    int h = *min_element(A.begin(), A.end());
    if(sum < (long)B)
        return 0;
    while(l<=h) {
        int mid = (l+h)/2;
        if(check(A,mid,B)) {
            ans = mid;
            l = mid+1;
        } else {
            h = mid-1; 
        }
    }
    return ans;
}
