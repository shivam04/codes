class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st; 
        int h3 = INT_MIN, h1 = INT_MAX; 
        for(int i=n-1;i>=0;i--) {
            h1 = nums[i]; 
            while (!st.empty() && st.top() < nums[i]) { 
                h3 = st.top(); 
                st.pop(); 
            }
            if(h1<h3)
                return true;
            st.push(nums[i]);
        }
        return false;
    }
};