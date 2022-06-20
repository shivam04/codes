class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        if(stockPrices.size()==1) return 0;
        sort(stockPrices.begin(), stockPrices.end());
        int n = stockPrices.size();
        __float128 pGG = -1000000000000.0;
        int ans = 0;
        for(int i=0;i<n-1;i++) {
            int num = (stockPrices[i+1][1]-stockPrices[i][1]);
            int dem = (stockPrices[i+1][0]-stockPrices[i][0]);
            __float128 gg = (__float128)((__float128)num/(__float128)dem);
            if(pGG!=gg) {
                ans++;
                pGG = gg;
            }
        }
        return ans;
    }
};