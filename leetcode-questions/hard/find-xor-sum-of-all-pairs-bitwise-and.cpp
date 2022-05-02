class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int XOR = 0;
        for(int num: arr1) {
            XOR ^= num;
        }
        int ans = 0;
        for(int num: arr2) {
            int p = num&XOR;
            ans ^= p;
        }
        return ans;
    }
};