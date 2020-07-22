class Solution {
public:
    vector<vector<int>> ans;
    vector<int> anss;
    void dfs(vector<vector<int>> &graph, int s) {
        anss.push_back(s);
        if(s==graph.size()-1) {
            ans.push_back(anss);
        } else {
            for(int i=0;i<graph[s].size();i++) {
                dfs(graph, graph[s][i]);
            }
        }
        anss.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0);
        return ans;
    }
};