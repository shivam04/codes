class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int l=0, mx = 0,longest = 0;
        int n = s.length();
        for(int r=0;r<n;r++) {
            mx = max(mx, ++cnt[s[r]-'A']);
            if ((r-l+1)-mx > k) {
                cnt[s[l]- 'A']--;
                l++;
            }
            longest = max(longest, r - l + 1);
        }
        return longest;
    }
};