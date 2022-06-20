vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int,int> ele;
    int n = A.size();
    vector<int> ans;
    for(int i=0;i<B;i++) {
        ele[A[i]]++;
    }
    ans.push_back(ele.size());
    for(int i=B;i<n;i++) {
        ele[A[i-B]]--;
        if(ele[A[i-B]]<=0) {
            ele.erase(A[i-B]);
        }
        ele[A[i]]++;
        ans.push_back(ele.size());
    }
    return ans;
}
