vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
   int n = A.size();
    sort(A.begin(),A.end());
    sort(B.begin(), B.end());

    priority_queue<pair<int,pair<int,int>>> pq;

    pq.push({A[n-1]+B[n-1], {n-1,n-1}});

    set<pair<int,int>> s;
    s.insert({n-1,n-1});
    vector<int> ans;
    for(int t=0;t<n;t++) {
        pair<int, pair<int, int> > temp = pq.top();
        pq.pop();
        ans.push_back(temp.first);

        int i = temp.second.first;
        int j = temp.second.second;

        int sum = A[i - 1] + B[j];
        pair<int, int> temp1 = make_pair(i - 1, j);

        if (s.find(temp1) == s.end()) {
            s.insert(temp1);
            pq.push({sum, temp1});
        }

        sum = A[i] + B[j - 1];
        temp1 = make_pair(i, j - 1);

        if (s.find(temp1) == s.end()) {
            s.insert(temp1);
            pq.push({sum, temp1});
        }
    }
    return ans;
}
