int Solution::singleNumber(const vector<int> &A) {
    int res = 0;
    for(int x=0;x<32;x++) {
        int cnt = 0;
        int k = (1<<x);
        for(int i=0;i<A.size();i++) {
            if(A[i]&k)
                cnt++;
        }
        if(cnt%3!=0) {
            res = res | k;
        }
    }
    return res;
}
