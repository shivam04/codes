vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> ans(A.size());
    ans[0] = -1;
    stack<int> s;
    s.push(0);
    for(int i=1;i<A.size();i++){
        while(!s.empty() and A[s.top()]>=A[i] ){
            s.pop();
        }
        if(s.size()==0)
        ans[i]=-1;
        else
        ans[i] = A[s.top()];
        s.push(i);
    }
    return ans;
}
