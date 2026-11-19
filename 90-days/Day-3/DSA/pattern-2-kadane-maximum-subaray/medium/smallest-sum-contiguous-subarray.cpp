class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        int curMin = INT_MAX;
        int ans = INT_MAX;
        
        for (int i=0;i<arr.size();i++) {
            if (curMin > 0) {
                curMin = arr[i];
            } else {
                curMin += arr[i];
            }
            
            ans = min(curMin, ans);
        }
        return ans;
    }
};