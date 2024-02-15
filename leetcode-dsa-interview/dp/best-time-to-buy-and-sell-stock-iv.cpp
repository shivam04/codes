class Solution {
public:
int dp[1003][103][2];
    int findAns(int b, int i, int cap, vector<int> &prices) {
        if (i == prices.size() or cap == 0) {
            return 0;
        }
        if (dp[i][cap][b] != -1) {
            return dp[i][cap][b];
        }
        int op1, op2;
        if (b==1) {
            op1 = findAns(1, i+1, cap, prices);
            op2 = -prices[i] + findAns(0, i+1, cap, prices);
        } else {
            op1 = findAns(0, i+1, cap, prices);
            op2 = prices[i] + findAns(1, i+1, cap-1, prices);
        }

        return dp[i][cap][b] = max(op1, op2);
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return findAns(1, 0, k, prices);
    }
};