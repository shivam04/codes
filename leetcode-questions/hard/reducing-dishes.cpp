class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int  sum = 0;
        int i = n-1;
        for(;i>=0;i--) {
            sum += satisfaction[i];
            if(sum<0)
                break;
        }
        i++;
        int ans = 0;
        int m = 1;
        for(;i<n;i++) {
            ans += (m*satisfaction[i]);
            m++;
        }
        return ans;
    }
};