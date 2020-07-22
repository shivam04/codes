class Solution {
public:
    vector<int> getVec(string pattern) {
        int t = 0;
        vector<int> p;
        map<char,int> mp;
        for(char c : pattern) {
            if(mp.find(c) == mp.end()) {
                t++;
                p.push_back(t);
                mp[c] = t;
            } else {
                p.push_back(mp[c]);
            }
        }
        return p;
    }
    void printVec(vector<int> p) {
        for(int i : p) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<int> p = getVec(pattern);
        //printVec(p);
        vector<string> ans;
        for(string s : words) {
            vector<int> q = getVec(s);
            if(p == q) {
                ans.push_back(s);
            }
        }
        return ans;
    }
};