string Solution::solve(string A) {
    stack<char> s;
    int i = 0;
    while (i < A.length()) {
        if (s.empty() || A[i] != s.top()) {
            s.push(A[i]);
            i++;
        }
        else{
            s.pop();
            i++;
        }
    }
    string ans = "";
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
