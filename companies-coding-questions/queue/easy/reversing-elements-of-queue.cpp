vector<int> Solution::solve(vector<int> &A, int B) {
    reverse(A.begin(), A.end());
    queue<int> q;
    while(B--) {
        q.push(A.back());
        A.pop_back();
    }

    while(!q.empty()) {
        A.push_back(q.front());
        q.pop();
    }
    reverse(A.begin(), A.end());
    return A;
}
