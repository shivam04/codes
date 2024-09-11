// O(N^2) O(N^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxLen = 1;
        for (int i = 0; i < n; ++i)
            dp[i][i] = true;
        int start = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }
        for (int k = 3; k <= n; ++k) {
            for (int i = 0; i < n - k + 1; ++i) {
                int j = i + k - 1;
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (k > maxLen) {
                        start = i;
                        maxLen = k;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};



// O(N^2) O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0, maxLen = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 1; j++) {
                int low = i;
                int hi = i + j; 
                 while (low >= 0 && hi < n && s[low] == s[hi]) {
                    int currLen = hi - low + 1;
                    if (currLen > maxLen) {
                        start = low;
                        maxLen = currLen;
                    }
                    low--;
                    hi++;
                 }
            }
        }
        return s.substr(start, maxLen);
    }
};


class Solution {
public:
    string longestPalindrome(string S) {
        int n = S.length();
        int maxL = 1;
        int start = 0;
        for(int i=0;i<n;i++) {
            int low = i-1;
            int high = i+1;
            while(low>=0 and S[low]==S[i]) {
                low--;
            }
            while(high<n and S[high]==S[i]) {
                high++;
            }
            while(low>=0 and high<n and S[low]==S[high]) {
                low--;
                high++;
            }
            if(maxL < high-low-1) {
                maxL = high-low-1;
                start = low+1;
            }
        }
        return S.substr(start, maxL); 
    }
};