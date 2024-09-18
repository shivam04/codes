class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
        set<char> s{'b', 'a', 'l', 'o', 'n'};
        for (char c: text) {
            if (s.find(c) != s.end()) {
                mp[c]++;
            }
        }

        int mini = INT_MAX;
        for (char c: s) {
            if (c == 'l' or c == 'o') {
                mp[c]/=2;
            }
        }

        for (char c: s) {
            mini = min(mini, mp[c]);
        }
        return mini;
    }
};