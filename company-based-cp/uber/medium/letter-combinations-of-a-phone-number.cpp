class Solution {
public:
    map<int, string> mp;
    void letterCombinationsUtil(vector<string> &ans, string digits, string s, int len) {
        if (len == digits.length()) {
            if (s != "")
                ans.push_back(s);
            return;
        }
        for(int j=0;j<mp[digits[len]-48].size();j++) {
            letterCombinationsUtil(ans, digits, s + mp[digits[len]-48][j], len+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        mp[0] = "0";
        mp[1] = "1";
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        string s = "";
        vector<string> ans;
        letterCombinationsUtil(ans, digits, s, 0);
        return ans;
    }
};