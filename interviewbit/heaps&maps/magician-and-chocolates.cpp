int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int> pq;
    for(int i=0;i<B.size();i++){
        pq.push(B[i]);
    }
    int  ans=0;
    while(A--){
        int q = pq.top();
        pq.pop();
        pq.push(q/2);
        ans= (ans%1000000007+q%1000000007)%1000000007;
    }
    return ans;
}