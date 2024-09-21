class Solution {
public:
    void ans(vector<string> &k, string s, int n, int o, int c) {
        if (c == n) {
            k.push_back(s);
            return;
        }
        if (o < n) {
            ans(k, s + "(", n, o + 1, c);
        }
        if (c < o) {
            ans(k, s + ")", n, o, c + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> k;
        ans(k, "", n, 0 , 0);
        return k;
    }
};