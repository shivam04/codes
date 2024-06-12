class Solution {
public:
    vector<int> countzeroesones(string str) {
        vector<int> count(2, 0);
        for (auto c: str) {
            count[c-48]++;
        } 
        return count;
    }
    int ans(vector<string> &strs, int i, int m, int n, vector<vector<vector<int>>> &dp) {
        if (i == strs.size()) {
            return 0;
        }
        if (dp[i][m][n] != -1) {
            return dp[i][m][n];
        }
        vector<int> count = countzeroesones(strs[i]);
        int incl = -1;
        if (m >= count[0] and n >= count[1]) {
            incl = ans(strs, i+1, m-count[0], n-count[1], dp) + 1;
        }
        int excl = ans(strs, i+1, m, n, dp);
        return dp[i][m][n] = max(incl, excl);
    } 
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<vector<int>>> dp(sz + 1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return ans(strs, 0, m, n, dp);
    }
};