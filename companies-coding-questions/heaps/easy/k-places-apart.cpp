vector<int> Solution::solve(vector<int> &A, int B) {
    if(B==0)
        return A;
    int n = A.size();
    vector<int> ans;
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int i=0;i<B+1;i++) {
        pq.push(A[i]);
    }
    for(int i=B+1;i<n;i++){
        ans.push_back(pq.top());
        pq.pop();
        pq.push(A[i]);
    }

    while(!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
