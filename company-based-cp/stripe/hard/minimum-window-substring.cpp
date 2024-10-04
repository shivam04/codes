class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        if (n1 < n2) {
            return "";
        }
        
        unordered_map<char, int> sCount, tCount;
        for (char c: t) {
            tCount[c]++;
        }

        int count = 0, minLength = INT_MAX;
        int startIdx = -1, start = 0;

        for (int i = 0; i < n1; i++) {
            char c = s[i];
            sCount[c]++;
            if (tCount[c] != 0 and sCount[c] <= tCount[c]) {
                count++;
            }
            if (count == n2) {
                while (sCount[s[start]] > tCount[s[start]] or tCount[s[start]] == 0) {
                    if (sCount[s[start]] > tCount[s[start]]) {
                        sCount[s[start]]--;
                    }
                    start++;
                }

                int len = i - start + 1;
                if (minLength > len) {
                    minLength = len;
                    startIdx = start;
                }
            }
        }
        if (startIdx == -1) {
            return "";
        }
        return s.substr(startIdx, minLength);
    }
};