struct Ele {
    double r;
    int p;
    int q;
};

struct MyCmp {
    bool operator()(Ele a, Ele b){
        return a.r < b.r;
    }
};
vector<int> Solution::solve(vector<int> &A, int B) {
    priority_queue<Ele, vector<Ele>, MyCmp> pq;

    for(int i=0;i<A.size();i++) {
        for(int j=i+1;j<A.size();j++) {
            int p = A[i];
            int q = A[j];
            if(p<q) {
                double r = ((double)p)/((double)q);
                Ele ele = {r,p,q};
                pq.push(ele);
            }
        }
    }
    vector<int> ans;
    while(pq.size()>B) {
        pq.pop();
    }

    if(pq.size()==B) {
        ans.push_back(pq.top().p);
        ans.push_back(pq.top().q);
        return ans;
    }
    return ans;
}
