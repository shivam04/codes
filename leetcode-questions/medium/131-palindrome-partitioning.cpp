// https://leetcode.com/problems/palindrome-partitioning/description/

class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while (i<j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void minPalPartion(string s, int i, vector<vector<string>> &ans, vector<string> &anss) {
        if (i==s.size()) {
            ans.push_back(anss);
            return;
        }
        for (int k = i; k < s.size(); k++) {
            if (isPalindrome(s, i, k)) {
                anss.push_back(s.substr(i, k-i+1));
                minPalPartion(s, k+1, ans, anss);
                anss.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> anss;
        minPalPartion(s, 0, ans, anss);
        return ans;
    }
};