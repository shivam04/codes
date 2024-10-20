class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        int n = arr.size();
        map<int,int> visit;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            visit[cur] = 1;

            int back = cur - arr[cur];
            int front = cur + arr[cur];

            if (arr[cur] == 0) {
                return true;
            }

            if (back < n and back >= 0 and visit.find(back) == visit.end()) {
                q.push(back);
            } 

            if (front >= 0 and front < n and visit.find(front) == visit.end()) {
                q.push(front);
            }
        }
        return false;
    }
};