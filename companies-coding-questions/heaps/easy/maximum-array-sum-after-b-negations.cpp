int Solution::solve(vector<int> &A, int B) {
    priority_queue <int, vector<int>, greater<int> > pq;
    for(int n:A) {
        pq.push(n);
    }
    int sum = 0;

    for(int i=0;i<B;i++) {
        int p = pq.top();
        pq.pop();
        pq.push(-p);
    }

    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    return sum;
}
