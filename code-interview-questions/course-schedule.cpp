class Solution
{
  public:
    void topologicalSort(int s, int visit[], stack<int> &st, vector<int> g[]) {
      visit[s] = 1;
      for(int t: g[s]) {
          if(visit[t]==0) {
              visit[t] = 1;
            topologicalSort(t, visit, st, g);
          } else if(visit[t]==1) {
              return;
          }
      }
      visit[s] = 2;
      st.push(s);
    }
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
        vector<int> g[n];
        for(vector<int> p: prerequisites) {
            g[p[1]].push_back(p[0]);
        }
        stack<int> st;
        int visit[n];
        memset(visit, 0, sizeof(visit));
        for(int i=0;i<n;i++) {
            if(visit[i] == 0)
                topologicalSort(i, visit, st, g);
        }
        vector<int> ans;
        if(st.size() != n) {
            return ans;
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};