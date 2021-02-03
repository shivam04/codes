class Solution {
public:
    int cpacity(vector<int> arr, int n, int maxLen) { 
        int total = 0, num = 1; 
        for (int i = 0; i < n; i++) { 
            total += arr[i]; 

            if (total > maxLen) { 
                total = arr[i]; 
                num++; 
            } 
        } 

        return num; 
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = 0;
        hi = accumulate(weights.begin(), weights.end(), 0);
        int n = weights.size();
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2; 
            int req = cpacity(weights, n, mid); 
            if(req <= D) {
                hi = mid;
            }
            else
                lo = mid+1;
        }
        return lo;
    }
};