vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> s;
    vector<int> ans(A.size());
    for(int i=0;i<A.size();i++) {
        while(!s.empty() and s.top()>=A[i]) {
            s.pop();
        }
        ans[i] = s.empty() ? -1: s.top();
        s.push(A[i]);
    }
    return ans;
}
