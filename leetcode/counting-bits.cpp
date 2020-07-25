class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for (int i = 0; i <= n; i++) {
            if (i <= 1) {
                res[i] = i&1;
            } else {
                res[i] = res[i>>1] + (i&1);
            }
        }
        return res;
    }
};