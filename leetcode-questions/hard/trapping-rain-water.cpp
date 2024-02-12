class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left[n];
        int right[n];
        left[0] = height[0];
        for(int i=1;i<n;i++) {
            left[i] = max(left[i-1], height[i]);
        }

        right[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--) {
            right[i] = max(right[i+1], height[i]);
        }
        int totalTrap = 0;
        for(int i=1;i<n-1;i++) {
            int val = min(left[i-1], right[i+1]);
            if (val > height[i]) {
                totalTrap += (val - height[i]);
            }
        }
        return totalTrap;
    }
};