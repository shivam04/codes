struct Cmp {
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
};
int Solution::solve(vector<int> &A, vector<int> &B) {
    int mod = 1000000007;
    vector<pair<int,int>> arr;

    int n = A.size();

    for(int i=0;i<n;i++) {
        arr.push_back({A[i],B[i]});
    }

    
    sort(arr.begin(), arr.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.first<b.first;
    });

    priority_queue<pair<int,int>, vector<pair<int,int>>, Cmp> pq;
    int ans = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        int slot_available;
        if (i == 0) {
            slot_available = arr[i].first;
        }
        else {
            slot_available = arr[i].first - arr[i - 1].first;
        }
        pq.push(arr[i]);
        while (slot_available > 0 && pq.size() > 0) {
            auto tt = pq.top();
            pq.pop();
            slot_available--;
            ans = (ans%mod + tt.second%mod)%mod;
        }
    }
    return ans;
}
