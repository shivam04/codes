class Solution {
public:
    vector<vector<int>> adj;
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        adj.resize(n+1, {});
        vector<int> inDegree(n+1, 0);
        for (vector<int> relation: relations) {
            adj[relation[0]].push_back(relation[1]);
            inDegree[relation[1]]++;
        }

        queue<int> q;
        for (int i=1;i<=n;i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        if (q.empty()) {
            return -1;
        }

        int step = 0, visitedCount = 0;

        while (!q.empty()) {
            int size = q.size();
            step++;
            while(size--) {
                visitedCount++;
                int cur = q.front();
                q.pop();
                for (int j: adj[cur]) {
                    inDegree[j]--;
                    if (inDegree[j] == 0) {
                        q.push(j);
                    }
                }
            }
        }

        return visitedCount == n ? step : -1;
    }
};