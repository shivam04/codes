int Solution::nTriang(vector<int> &A) {
    sort(A.begin(),A.end());
    int n = A.size();
    int count = 0;
    int mod = 1000000000+7;
    for(int i=0;i<n-2;i++){
        int l= i+1;
        int r =i+2;
        for(;l<n;l++){
            while(r<n and A[i]+A[l]>A[r])
            r++;
            count = (count+r-l-1)%mod;
        }
    }
    return count;
}