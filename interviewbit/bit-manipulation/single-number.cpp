int Solution::singleNumber(const vector<int> &A) {
    int k = 0;
    for(int i=0;i<A.size();i++){
        k = k^A[i];
    }
    return k;
}
