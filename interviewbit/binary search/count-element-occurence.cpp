int Solution::findCount(const vector<int> &A, int B) {
    int k = lower_bound(A.begin(),A.end(),B)-A.begin();
    int p = upper_bound(A.begin(),A.end(),B)-A.begin();
    return (p-k);
}
