class Solution {
public:
    int getCurrentArea(stack<int> &s, vector<int> &height, int i) {
        int tp = s.top();
        s.pop();
        return height[tp]*(s.empty() ? i : i-s.top()-1);
    }
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int i = 0;
        int area = 0;
        while(i < heights.size()) {
            if (s.empty() || heights[s.top()] <= heights[i]) {
                s.push(i++);
            } else {
                area = max(area, getCurrentArea(s, heights, i));
            }
        }
        while(!s.empty()) {
            area = max(area, getCurrentArea(s, heights, i));
        }
        return area;
    }
};