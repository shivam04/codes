class Solution{
public:
    int BIT[100005];
    void update(int x, int delta, int n) {
          for(; x <= n; x += x&-x)
            BIT[x] += delta;
    }
    int query(int x) {
         int sum = 0;
         for(; x > 0; x -= x&-x)
            sum += BIT[x];
         return sum;
    }
    vector<int> findSurpasser(int arr[], int n) {
        vector<int> sA(arr,arr+n);
        vector<int> ans(n);
        sort(sA.begin(), sA.end());
        for(int i=0;i<n;i++) {
            arr[i] = lower_bound(sA.begin(), sA.end(), arr[i]) - sA.begin() + 1;
        }
        for(int i=0;i<=n;i++) {
            BIT[i] = 0;
        }
        int cnt = 0;
        for(int i=n-1;i>=0;i--) {
            ans[i] = query(n) - query(arr[i]-1);
            update(arr[i], 1, n);
        }
        return ans;
    }
};