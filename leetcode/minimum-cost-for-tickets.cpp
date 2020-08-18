class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[366];
        dp[0] = 0;
        int n = days.size();
        int j=0;
        for(int i=1;i<366;i++) {
            dp[i] = costs[0] + dp[i - 1];
            if(i>=7) {
                dp[i] = min(dp[i], dp[i-7] + costs[1]);
            }
            if(i>=30) {
                dp[i] = min(dp[i], dp[i-30] + costs[2]);
            }
            if(j < n && days[j] == i) {
                j++;
            } else {
                dp[i] = min(dp[i], dp[i - 1]);
            }
        }
        
        return dp[365];
    }
};