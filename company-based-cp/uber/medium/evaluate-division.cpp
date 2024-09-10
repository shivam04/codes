class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string,unordered_map<string,double>> graph;
        for(int i=0;i<n;i++) {
            vector<string> branch = equations[i];
            double val = values[i];
            graph[branch[0]][branch[1]] = val;
            graph[branch[1]][branch[0]] = 1.0/val;
        }

        vector<double> ans;
        for (vector<string> query: queries) {
            string startNode = query[0];
            string endNode = query[1];
            double res = 1.0;
            queue<pair<string, double>> q;
            q.push({startNode, 1.0});
            unordered_map<string, bool> visit;
            bool find = false;
            while (!q.empty()) {
                auto t = q.front();
                q.pop();
                string node = t.first;
                double val = t.second;
                visit[node] = true;
                if (node == endNode and graph.find(startNode) != graph.end()) {
                    find = true;
                    ans.push_back(val);
                    break;
                }
                for (auto nei: graph[node]) {
                    if (!visit[nei.first]) {
                        visit[nei.first] = true;
                        q.push({nei.first, nei.second*val});
                    }
                }
            }
            if (!find) {
                ans.push_back(-1.0);
            }
        }
        return ans;
    }
};