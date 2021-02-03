class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans;
        int n=T.size();
        ans.resize(n);
        stack<int> s;
        s.push(0);
        for(int i=1;i<n;i++) {
            while(!s.empty() and T[s.top()]<T[i]) {
                ans[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};