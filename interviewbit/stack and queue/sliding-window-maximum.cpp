vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    deque<int> dq;
    vector<int> ans;
    int i;
    for(i=0;i<B;i++){
        while(dq.size()>0 and A[dq.back()]<=A[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    int n = A.size();
    for(;i<n;i++){
        ans.push_back(A[dq.front()]);
        while(dq.size()>0 and dq.front()<=i-B){
            dq.pop_front();
        }
        while(!dq.empty() and A[dq.back()]<=A[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(A[dq.front()]);
    return ans;
}
