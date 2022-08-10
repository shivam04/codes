struct MyCmp {
    bool operator()(auto a, auto b){
        return a.first+a.second > b.first+b.second;
    }
};
int Solution::solve(vector<int> &A, int B) {
    priority_queue<pair<long,long>, vector<pair<long,long>>, MyCmp> pq;
    int n = A.size();
    for(int i=0;i<n;i++) {
        pq.push({(long)A[i],(long)A[i]});
    }

    while(B--) {
        auto p = pq.top();
        pq.pop();
        pq.push({p.first+p.second, p.second});
    }

    long maxi = -100000000000000;
    while(!pq.empty()) {
        maxi = max(pq.top().first, maxi);
        pq.pop();
    }
    return maxi;
}
