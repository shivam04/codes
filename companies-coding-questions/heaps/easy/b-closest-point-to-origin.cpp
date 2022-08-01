vector<vector<int> > Solution::solve(vector<vector<int> > &A, int B) {
    auto cmp = [](vector<int> a, vector<int> b){
        int dista = a[0]*a[0] + a[1]*a[1];
        int distb = b[0]*b[0] + b[1]*b[1];
        return dista > distb;
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
    for(auto n:A) {
        pq.push({n[0],n[1]});
    }
    vector<vector<int>> ans;
    while(B--) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}



//struct compare
struct CustomCompare
{
    bool operator()(vector<int> a, vector<int> b){
        int dista = a[0]*a[0] + a[1]*a[1];
        int distb = b[0]*b[0] + b[1]*b[1];
        return dista > distb;
    }
};
vector<vector<int> > Solution::solve(vector<vector<int> > &A, int B) {
    priority_queue<vector<int>, vector<vector<int>>, CustomCompare> pq;
    for(auto n:A) {
        pq.push({n[0],n[1]});
    }
    vector<vector<int>> ans;
    while(B--) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
