vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    vector<int> ans;
    deque<int> q;
    for(int i=0;i<B;i++) {
        while(!q.empty() and A[q.back()] <= A[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    

    for(int i=B;i<A.size();i++) {
        ans.push_back(A[q.front()]);
        while(!q.empty() and q.front() <= i-B) {
            q.pop_front();
        }
        while(!q.empty() and A[q.back()] <= A[i]) {
            q.pop_back();
        }
        q.push_back(i);
        
    }
    ans.push_back(A[q.front()]);
    return ans;

}
