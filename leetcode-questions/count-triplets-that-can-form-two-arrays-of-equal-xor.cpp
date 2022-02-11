class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq{{0, 1}};    
        unordered_map<int, int> sum;
        int X = 0;
        for(int i=0;i<n;i++) {
            X = X^arr[i];
            ans += freq[X] * i - sum[X];
            ++freq[X];
            sum[X] += i + 1;
        }
        return ans;
    }
};