class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0;
        int ans = 0;

        int r = 1;
        while (r < n) {
            if (prices[l] < prices[r]) {
                ans = max(ans, prices[r]-prices[l]);
            } else {
                l = r;
            }
            r++;
        }
        return ans;
    }
};