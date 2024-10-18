class Solution {
public:
    bool isSubSequence(string d, string s) {
        int j = 0;
        for (int i=0;i<s.length();i++) {
            if (d[j] == s[i]) {
                j++;
            }
        }
        return j == d.length();
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](string a, string b) {
            if (a.length() != b.length()) {
                return a.length() > b.length();
            }
            return a < b;
        });
        for (string d: dictionary) {
            if (isSubSequence(d, s)) {
                return d;
            }
        }
        return "";
    }
};