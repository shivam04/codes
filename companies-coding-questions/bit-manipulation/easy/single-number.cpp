int Solution::singleNumber(const vector<int> &A) {
    int ans = 0;
    for(int n: A) {
        ans = ans ^ n;
    }
    return ans;
}
