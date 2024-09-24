// O(n^2) TLE

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int res = INT_MAX;
        int ans = -1;
        for(int i=0;i<=n;i++) {
            int penalty = 0;
            for (int j=1;j<=n;j++) {
                if (i < j) {
                    penalty += (customers[j-1] == 'Y');
                } else {
                    penalty += (customers[j-1] == 'N');
                }
            }
            if (penalty < res) {
                res = penalty;
                ans = i;
            }
        }
        return ans;
    }
};



// O(n)
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int minPenalty = 0, curPenalty = 0;
        int earliestHour = 0;
        for (int i = 0; i < n; i++) {
            char ch = customers[i];
            if (ch == 'Y') {
                curPenalty--;
            } else {
                curPenalty++;
            }
            if (curPenalty < minPenalty) {
                earliestHour = i + 1;
                minPenalty = curPenalty;
            }
        }
        return earliestHour;
    }
};