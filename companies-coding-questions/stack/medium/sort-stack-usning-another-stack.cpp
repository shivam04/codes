vector<int> Solution::solve(vector<int> &A) {
    stack<int> s,t;
    for(int i=0;i<A.size();i++) {
        t.push(A[i]);
    }
    
    while(!t.empty()) {
        int tmp = t.top();
        t.pop();
        while (!s.empty() && s.top() > tmp) {
            t.push(s.top());
            s.pop();
        }
        s.push(tmp);
    }
    vector<int> ans;
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
