vector<int> Solution::nextGreater(vector<int> &A) {
    int n = A.size();
    stack<int> s;
    vector<int> nxtG(n,0);
    for (int i = n-1; i >=0; --i) {
        while(!s.empty() and s.top() <= A[i]) {
            s.pop();
        }
        nxtG[i] = s.empty() ? -1 : s.top();
        s.push(A[i]);
    }
    return nxtG;
}
