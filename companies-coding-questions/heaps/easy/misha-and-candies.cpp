int Solution::solve(vector<int> &A, int B) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int n:A) {
        pq.push(n);
    }
    int ans = 0;
    while(!pq.empty() and pq.top()<=B) {
        int s = pq.top();
        pq.pop();
        int k = floor(s/2);
        ans += k;
        if(!pq.empty()) {
            int t = pq.top();
            pq.pop();
            t += (s-k);
            pq.push(t);
        }
    }
    return ans;
}
