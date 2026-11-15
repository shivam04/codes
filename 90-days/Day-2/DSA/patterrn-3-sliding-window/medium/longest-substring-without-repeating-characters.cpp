class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int n = s.length();
        unordered_map<int, int> window;
        int maxL = 0;
        int start = 0;
        while(i<n) {
            if (window.find(s[i]) != window.end()) {
                start = max(start, window[s[i]] + 1);
            }
            window[s[i]] = i;
            if (maxL < i-start+1) {
                maxL = i - start + 1;
            }
            i++;
        }
        return maxL;
    }
};