class Solution {
public:
    int bananaPerHour(vector<int>& piles, int m) {
        int requiredHour = 0;
        for(int pile: piles) {
            if (pile%m != 0) {
                requiredHour += ((pile/m) + 1);
            } else {
                requiredHour += (pile/m);
            }
        }
        return requiredHour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int requiredHour = bananaPerHour(piles, mid);
            if (requiredHour <= h) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        return lo;
    }
};