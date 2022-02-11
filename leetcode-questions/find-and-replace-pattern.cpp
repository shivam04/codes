class Solution {
public:
    vector<int> getPattern(string pat) {
        int t = 0;
        map<char,int> mp;
        vector<int> p;
        for(char c : pat) {
            if(mp.find(c) == mp.end()) {
                mp[c] = ++t;
                p.push_back(mp[c]);
            } else {
                p.push_back(mp[c]);
            }
        }
        return p;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<int> p = getPattern(pattern);
        vector<string> ans;
        for(string s : words) {
            vector<int> q = getPattern(s);
            if(p == q) {
                ans.push_back(s);
            }
        }
        return ans;
    }
};