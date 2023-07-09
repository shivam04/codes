class Solution {
public:
    int dp[605][102][102];
    vector<unordered_map<int,int>> vmp;
    int ans(int sz, int m, int n) {
        if (sz < 0)
            return 0;

        if (dp[sz][m][n] != -1)
            return dp[sz][m][n];

        if (m < vmp[sz][0] || n < vmp[sz][1]) {
            dp[sz][m][n] = ans(sz-1, m, n);
            return dp[sz][m][n];
        }

       dp[sz][m][n] = max(1+ans(sz-1, m-vmp[sz][0], n-vmp[sz][1]), ans(sz-1, m, n));
        return dp[sz][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vmp.clear();
        vmp.resize(sz);
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<sz; i++) {
            for(char c: strs[i]) {
                vmp[i][c-48]++;
            }
        }
        return ans(sz-1, m, n);
    }
};


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        int dp[sz+1][m+1][n+1];
        vector<unordered_map<int,int>> vmp;
        vmp.resize(sz+2);
        for(int i=1;i<=sz; i++) {
            for(char c: strs[i-1]) {
                vmp[i][c-48]++;
            }
        }

        for(int i=0;i<=sz;i++) {
            for (int j = 0; j <= m; j ++) {
                for (int k = 0; k <= n; k ++) {
                    if (i==0) {
                        dp[i][j][k] = 0;
                    } else if (j>=vmp[i][0] and k>=vmp[i][1]) {
                        dp[i][j][k] = max(1 + dp[i-1][j-vmp[i][0]][k-vmp[i][1]], dp[i-1][j][k]);
                    } else {
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }
        return dp[sz][m][n];
    }
};

2D
class Solution {
  public int findMaxForm(String[] strs, int m, int n) {
      int[][] dp = new int[m + 1][n + 1];
      for (String s : strs) {
        int[] counts = countZeroOnes(s);
        for (int i = m; i >= counts[0]; i--) {
          for (int j = n; j >= counts[1]; j--) {
            dp[i][j] = Math.max(1 + dp[i - counts[0]][j - counts[1]], dp[i][j]);
          }
        }
      }
      return dp[m][n];
  }
  private int[] countZeroOnes(String s) {
       int[] res = new int[2];
       for (char ch : s.toCharArray()) {
         res[ch - '0']++;
       }
       return res;
  }
}