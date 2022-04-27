class Solution {
public:
    int minOperations(int n) {
        vector<int> arr;
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += (2*i+1);
        }
        int avg = sum/n;
        sum = 0;
        for(int i=0;i<n/2;i++) {
            sum += abs(avg-(2*i+1));
        }
        return sum;
    }
};