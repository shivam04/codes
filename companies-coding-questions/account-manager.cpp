vector<int> Solution::solve(int A, int B, vector<int> &C) {
    queue<pair<int,int>> q;
    queue<int> worker;
    for(int i=0;i<A;i++) {
        worker.push(i);
    }
    vector<int> ans;
    for(int i=0;i<C.size();i++) {
        if(q.empty()) {
            int w = worker.front();
            worker.pop();
            q.push({w, C[i]+B});
            ans.push_back(worker.size());
        } else {
            while(!q.empty() and q.front().second <= C[i]) {
                worker.push(q.front().first);
                q.pop();
            }
            if(worker.size()==0) {
                ans.push_back(0);
            } else {
                int w = worker.front();
                worker.pop();
                q.push({w,C[i]+B});
                ans.push_back(worker.size());
            }
        }
    }
    return ans;
}


//Light (Single queue)
vector<int> Solution::solve(int A, int B, vector<int> &C) {
    queue<int> q;
    vector<int> ans;
    for(int i=0;i<C.size();i++) {
        while(!q.empty() and q.front() <= C[i]) {
            q.pop();
        }
        if(q.size()==A) {
            ans.push_back(0);
        } else {
            q.push(C[i]+B);
            ans.push_back(A-(int)q.size());
        }
    }
    return ans;
}
