class Solution {
public:
    int ladderLength(string start, string target, vector<string>& wordList) {
        set<string> s;
        for(int i=0;i<wordList.size();i++) {
            s.insert(wordList[i]);
        }
        if(s.find(target) == s.end())
            return 0;
        map<string, vector<string>> umap;
        for(int i = 0; i < start.size(); i++) { 
            string str = start.substr(0,i) + "*" +  start.substr(i+1); 
            umap[str].push_back(start); 
        }
        for(auto it = s.begin(); it != s.end(); it++) {
            string word = *it;
            for(int j = 0; j < word.size(); j++) { 
              string str = word.substr(0,j) + "*" +   word.substr(j+1); 
              umap[str].push_back(word); 
            } 
        }
        queue<pair<string, int>> q; 
        map<string, int> visited;
        q.push({start,1}); 
        visited[start] = 1; 
        while(!q.empty()) {
            pair<string, int> p = q.front();
            q.pop();
            string word = p.first; 
            int dist = p.second; 
            if(word == target) {
                return dist;
            }
            for(int i = 0; i < word.size(); i++) { 
                string str = word.substr(0,i) + "*" +   word.substr(i+1); 
                vector<string> nextNodes = umap[str];
                for(int j=0;j<nextNodes.size();j++) {
                    if(visited[nextNodes[j]] == 0) {
                        visited[nextNodes[j]] = 1;
                        q.push({nextNodes[j], dist + 1});
                    }
                }
            }
        }
        return 0;
    }
};