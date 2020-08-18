class Solution {
public:
    void ans(vector<string> &k, string s, int n, int o, int c) {
        if(c==n) {
            if(s!="")
                k.push_back(s);
            return;
        }
        if(o<n) {
            s += "(";
            ans(k, s, n, o+1, c);
            s.pop_back();
        }
        if(o>c) {
            s += ")";
            ans(k, s, n, o, c+1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> k;
        ans(k, "", n, 0 ,0);
        return k;
    }
};