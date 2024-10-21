class Solution {
public:
    int n;
    map<int, int> range;
    Solution(vector<int>& w) {
        srand((unsigned)time(0)); 
        double sum = 0;
        for(int we: w) {
            double p = (double)we;
            sum = sum + p;
        }
        n = w.size();
        int last = 0;
        for(int i=0;i<n;i++) {
            double p = (double)w[i];
            int prob = ceil(p*100.0/sum);
            for (int j=last; j<last+prob;j++) {
                range[j] = i;
            }
            last = last + prob;
        }
    }
    
    int pickIndex() {
        int rangeSize = range.size();
        int rangeKey = rand()%rangeSize;
        return range[rangeKey];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */