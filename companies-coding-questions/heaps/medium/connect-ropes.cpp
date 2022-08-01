int Solution::solve(vector<int> &A) {
    int n = A.size();
    priority_queue <int, vector<int>, greater<int> > pq;
    for(int num : A) {
        pq.push(num);
    }
    int ans = 0;
    while(pq.size()>1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans += (a+b);
        pq.push(a+b);
    }
    return ans;
}
