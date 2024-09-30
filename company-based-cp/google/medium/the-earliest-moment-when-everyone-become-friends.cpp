class Solution {
public:
    void initialize(vector<int> &arr, int n) {
        for (int i=0;i<n;i++) {
            arr.push_back(i);
        }
    }
    int root(vector<int> &arr, int i) {
        while(arr[i] != i) {
            i = arr[i];
        }
        return i;
    }
    void unionFriend(vector<int> &arr, int x, int y) {
        int rootX = root(arr, x);
        int rootY = root(arr, y);
        arr[rootX] = rootY;
    }
    bool find(vector<int> &arr, int x, int y) {
        return (root(arr, x) == root(arr, y));
    }
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] <= b[0];
        });
        vector<int> arr;
        initialize(arr, n);
        for (vector<int> v: logs) {
            unionFriend(arr, v[1], v[2]);
            int cnt = 0;
            for (int i=0;i<n;i++) {
                cnt += find(arr, 0, i);
            }
            if (cnt == n) {
                return v[0];
            }         
        }
        return -1;
    }
};