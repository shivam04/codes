bool cmp(string a, string b) {
    return a.length() < b.length();
}
class Solution {
public:
    vector<string> splitF(string folder, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(folder);
        while (getline(tokenStream, token, delimiter)){
          tokens.push_back(token);
        }
        return tokens;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(), cmp);
        set<string> s;
        vector<string> ans; 
        for(auto f : folder) {
            if(s.find(f) != s.end()) {
                continue;
            }
            vector<string> result = splitF(f, '/');
            bool flag = false;
            string cp = "";
            for(int i=1;i<result.size();i++) {
                cp += "/" + result[i];
                if(s.find(cp) != s.end()) {
                    flag = true;
                    continue;
                }
            }
            if(flag) {
                continue;
            }
            ans.push_back(f);
            s.insert(f);
        }
        return ans;
    }
};