// O(n^2)

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int lps[n][n];
        int mlps = 1;
        int silps = 0;
        memset(lps,0,sizeof(lps));
        for(int i=0;i<n;i++) {
            lps[i][i] = 1;
        }

        for(int i=0;i<n-1;i++) {
           if(s[i] == s[i+1]) {
               lps[i][i+1] = 1;
               mlps = 2;
               silps = i;
           }
        }

        for(int len=3;len<=n;len++) {
            for(int i=0;i<n-len+1;i++) {
                int j = i+len-1;
                if (s[i]==s[j] and lps[i+1][j-1]) {
                    lps[i][j] = 1;
                    if (len > mlps) {
                        mlps = len;
                        silps = i;
                    }
                }
            }
        }

        return s.substr(silps, mlps);
    }
};

// O(n^2)

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