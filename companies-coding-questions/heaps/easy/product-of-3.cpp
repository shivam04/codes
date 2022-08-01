vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    priority_queue<int> pq;
    vector<int> ans;
    for(int i=0;i<n;i++) {
        pq.push(A[i]);
        if(i<2) {
            ans.push_back(-1);
        } else {
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            int t = pq.top();
            pq.pop();
            ans.push_back(f*s*t);
            pq.push(f);
            pq.push(s);
            pq.push(t);
        }
    }
    return ans;
}
