class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        ans.resize(n, -1);
        stack<int> s;
        for(int i=2*n-1;i>0;i--) {
            while(!s.empty() and nums[s.top()] <= nums[i%n]) {
                s.pop();
            }
            ans[i%n] = s.empty() ? -1 : nums[s.top()];
            s.push(i%n);
        }
        return ans;
    }
};