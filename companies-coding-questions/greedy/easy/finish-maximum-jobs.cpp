int Solution::solve(vector<int> &A, vector<int> &B) {
    vector<pair<int,int>> arr;

    int n = A.size();

    for(int i=0;i<n;i++) {
        arr.push_back({A[i],B[i]});
    }

    sort(arr.begin(), arr.end(), [](pair<int,int> a, pair<int,int> b) {
        if(a.second==b.second)
            return a.first < b.first;
        return a.second < b.second;
    });
    int ans = 0;
    for(int i=0;i<n;i++) {
        int p = i+1;
        while(p<n and arr[p].first<arr[i].second) {
            p++;
        }
        ans++;
        i = p-1;
    }
    return ans;
    
}
