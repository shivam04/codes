int Solution::solve(int A, int B, vector<int> &C) {
    stack<int> s;
    int ch = B;
    for(int i=0;i<A;i++) {
        int id = C[i];
        if(id > 0) {
            s.push(ch);
            ch = C[i]; 
        } else {
            int t = s.top();
            s.pop();
            ch = t;
        }
    }
    return ch;
}
