int Solution::cntBits(vector<int> &A) {
    long long int ans = 0;
    int count;
    int mod = 1000000007;

    for(int i = 0; i < 31; i++){
        count = 0;
        for(int j = 0; j < A.size(); j++){
            if(A[j] & (1 << i)){
                count++;
            }
        }
        ans = ans + (2*count*(A.size()-count));
        ans = ans%mod;
    }
    
    return (int)ans;
}
