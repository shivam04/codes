class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> sumCount;
        sumCount[0] = 1;
        for (int i=0;i<nums.size();i++) {
            sum += nums[i];
            if (sumCount.find(sum-k) != sumCount.end()) {
                count += sumCount[sum-k];
            }
            sumCount[sum]++;
        }
        return count;
    }
};