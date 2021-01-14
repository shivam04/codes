#include <bits/stdc++.h>

using namespace std;

const int maxn = 4000 + 5;
const int mod = 1000000000 + 7;
map < vector < int > , int > mp;
int dp[maxn];
string s;
int T, V, S;

int main() {


  cin >> T;
  for (int _ = 1; _ <= T; ++_) {
    cin >> V >> S;
    mp.clear();
    for (int i = 0; i < V; ++i) {
      cin >> s;
      vector < int > a(26);
      for (int i = 0; i < s.length(); ++i) a[s[i] - 'a']++;
      mp[a]++;
    }

    printf("Case #%d:", _);
    for (int i = 0; i < S; ++i) {
      cin >> s;
      dp[0] = 1;
      for (int j = 0; j < s.length(); ++j) {
        dp[j + 1] = 0;
        vector < int > a(26);
        for (int k = 0; k < 20 && j - k >= 0; ++k) {
          a[s[j - k] - 'a']++;
          auto it = mp.find(a);
          if (it != mp.end()) {
            dp[j + 1] = (dp[j + 1] + (long long) dp[j - k] * it -> second) % mod;
          }
        }
      }
      printf(" %d", dp[s.length()]);
    }
    printf("\n");
  }

  return 0;
}