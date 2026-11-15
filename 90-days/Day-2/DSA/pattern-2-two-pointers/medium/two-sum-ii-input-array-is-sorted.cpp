class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size() - 1;
        int i=0;
        while(i<n) {
            if(numbers[i] + numbers[n] == target) {
                return {i+1, n+1};
            } else if(numbers[i] + numbers[n] > target) {
                n--;
            } else {
                i++;
            }
        }
        return {};
    }
};