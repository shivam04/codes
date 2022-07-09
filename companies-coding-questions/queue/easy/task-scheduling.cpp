int Solution::solve(vector<int> &A, vector<int> &B) {
    deque<int> q;
    for(int a: A) {
        q.push_back(a);
    }
    int ans = 0;
    int i = 0;
    while(i<B.size() and !q.empty()) {
        int b = B[i];
        if(q.front()==b) {
            ans++;
            q.pop_front();
            i++;
        } else {
            while(q.front()!=b) {
                ans++;
                int t = q.front();
                q.pop_front();
                q.push_back(t);
            }
        }
    }
    return ans;
}
