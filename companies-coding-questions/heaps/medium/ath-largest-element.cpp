vector<int> Solution::solve(int A, vector<int> &B) {
    int n = B.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    for(int i=0;i<A;i++){
        pq.push(B[i]);
        ans.push_back(-1);
    }

    ans.pop_back();
    ans.push_back(pq.top());

    for(int i=A;i<n;i++) {
        if(B[i]>pq.top()) {
            pq.pop();
            pq.push(B[i]);
        }
        ans.push_back(pq.top());
    }
    return ans;
}
