class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> g;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        for(int i=0;i<n;i++) {
            g[equations[i][0]].push_back({equations[i][1], values[i]});
            if(values[i] != 0)
                g[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }
        vector<double> ans;
        for(int i=0;i<queries.size();i++) {
            string a = queries[i][0];
            string b = queries[i][1];
            queue<pair<string,double>> q;
            q.push({a,1.0});
            unordered_set<string> visited;
            bool flag = false;
            while(!q.empty()) {
                pair<string,double> t = q.front();
                q.pop();
                string u = t.first;
                double x = t.second;
                if(u==b and g.count(u)>0){
                    ans.push_back(x);
                    flag = true;
                    break;
                }
                visited.insert(u);
                for(pair<string,double> tt : g[u]) {
                    if(!visited.count(tt.first)) {
                        q.push({tt.first, tt.second*x});
                    }
                }
            }
            if(!flag)
            ans.push_back(-1);
        }
        return ans;
    }
};