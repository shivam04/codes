vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    priority_queue<pair<int, pair<int, int> > > pq;
    int N = A.size();
    vector<int> ans;
    set<pair<int, int> > my_set;
    pq.push(make_pair(A[N - 1] + B[N - 1],make_pair(N-1, N-1)));
    my_set.insert(make_pair(N - 1, N - 1));
    for(int k=0;k<N;k++){
        pair<int, pair<int, int> > temp = pq.top();
        pq.pop();
        ans.push_back(temp.first);
        int i = temp.second.first;
        int j = temp.second.second;
        int sum = A[i - 1] + B[j];
        pair<int, int> temp1 = make_pair(i - 1, j);
        if (my_set.find(temp1) == my_set.end()) {
            pq.push(make_pair(sum, temp1));
            my_set.insert(temp1);
        }
        sum = A[i] + B[j - 1];
        temp1 = make_pair(i, j - 1);
        if (my_set.find(temp1) == my_set.end()) {
            pq.push(make_pair(sum, temp1));
            my_set.insert(temp1);
        }
    }
    return ans;
}